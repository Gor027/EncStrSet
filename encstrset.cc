#include "encstrset.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iomanip>

using namespace std;

#ifdef DNDEBUG
const bool debug = false;
#else
const bool debug = true;
#endif

#define SET_NOT_EXIST(x) ": set #" << x << " does not exist"

#define STRING_OR_NULL(x) "\"" << (x == nullptr ? "NULL" : x) << "\""

#define HEX_CIPHER(x)                                                     \
    for (size_t i = 0; i < x.length(); i++)                               \
    {                                                                     \
        cerr << hex << uppercase << setw(2) << setfill('0') << (int)x[i]; \
        if (i != x.length() - 1)                                          \
        {                                                                 \
            cerr << " ";                                                  \
        }                                                                 \
    }

#define DEBUG_WITH_CYPHER(x, cypher, y) \
    do                                  \
    {                                   \
        if (debug)                      \
        {                               \
            cerr << __func__ << x;      \
            HEX_CIPHER(cypher);         \
            cerr << y << "\n";          \
        }                               \
    } while (0);

#define DEBUG(x)                           \
    do                                     \
    {                                      \
        if (debug)                         \
            cerr << __func__ << x << "\n"; \
    } while (0)

namespace
{
    const bool active = true;
    const bool notActive = false;
    using StrSet = unordered_set<string>;
    using Active = bool;
    using Sets = vector<pair<StrSet, Active>>;

    Sets allSets;

    bool isActive(unsigned long id)
    {
        return allSets[id].second;
    }

    bool setExist(unsigned long id)
    {
        return ((unsigned long)allSets.size() > id && isActive(id));
    }

    void deactivateSet(unsigned long id)
    {
        allSets[id].second = notActive;
    }

    string encode(const char *value, const char *key)
    {
        string encodeResult = value;
        if (key != nullptr && strlen(key) > 0)
        {
            for (size_t i = 0; i < encodeResult.length(); i++)
            {
                encodeResult[i] ^= key[i % strlen(key)];
            }
        }
        return encodeResult;
    }
} // namespace

namespace jnp1
{
    unsigned long encstrset_new()
    {
        DEBUG("()");
        StrSet newSet;
        allSets.emplace_back(newSet, active);
        DEBUG(": set #" << (unsigned long)allSets.size() - 1 << " created");
        return (unsigned long)allSets.size() - 1;
    }

    void encstrset_clear(unsigned long id)
    {
        DEBUG("(" << id << ")");
        if (setExist(id))
        {
            allSets[id].first.clear();
            DEBUG(": set #" << id << " cleared");
        }
        else
        {
            DEBUG(SET_NOT_EXIST(id));
        }
    }

    void encstrset_delete(unsigned long id)
    {
        DEBUG("(" << id << ")");
        if (setExist(id))
        {
            allSets[id].first.clear();
            deactivateSet(id);
            DEBUG(": set #" << id << " deleted");
        }
        else
        {
            DEBUG(SET_NOT_EXIST(id));
        }
    }

    size_t encstrset_size(unsigned long id)
    {
        DEBUG("(" << id << ")");
        if (setExist(id))
        {
            DEBUG(": set #" << id << " contains " << allSets[id].first.size() << " element(s)");
            return allSets[id].first.size();
        }
        else
        {
            DEBUG(SET_NOT_EXIST(id));
            return 0;
        }
    }

    bool encstrset_insert(unsigned long id, const char *value, const char *key)
    {
        DEBUG("(" << id << ", " << STRING_OR_NULL(value) << ", " << STRING_OR_NULL(key) << ")");
        if (value == nullptr)
        {
            DEBUG(": invalid value (NULL)");
            return false;
        }
        if (setExist(id))
        {
            string encodedValue = encode(value, key);
            if (allSets[id].first.find(encodedValue) == allSets[id].first.end())
            {
                allSets[id].first.insert(encodedValue);
                DEBUG_WITH_CYPHER(":set #" << id << ", cypher \"", encodedValue, "\" inserted");
                return true;
            }
            else
            {
                DEBUG_WITH_CYPHER(":set #" << id << ", cypher \"", encodedValue, "\" was already present");
            }
        }
        else
        {
            DEBUG(SET_NOT_EXIST(id));
        }

        return false;
    }

    bool encstrset_remove(unsigned long id, const char *value, const char *key)
    {
        DEBUG("(" << id << ", " << STRING_OR_NULL(value) << ", " << STRING_OR_NULL(key) << ")");
        if (value == nullptr)
        {
            DEBUG(": invalid value (NULL)");
            return false;
        }
        if (setExist(id))
        {
            string encodedValue = encode(value, key);
            if (allSets[id].first.find(encodedValue) != allSets[id].first.end())
            {
                DEBUG_WITH_CYPHER(":set #" << id << ", cypher \"", encodedValue, "\" removed");
                allSets[id].first.erase(encodedValue);
                return true;
            }
            else
            {
                DEBUG_WITH_CYPHER(":set #" << id << ", cypher \"", encodedValue, "\" was not present");
            }
        }
        else
        {
            DEBUG(SET_NOT_EXIST(id));
        }

        return false;
    }

    bool encstrset_test(unsigned long id, const char *value, const char *key)
    {
        DEBUG("(" << id << ", " << STRING_OR_NULL(value) << ", " << STRING_OR_NULL(key) << ")");
        if (setExist(id))
        {
            string encodedValue = encode(value, key);
            if (allSets[id].first.find(encodedValue) != allSets[id].first.end())
            {
                DEBUG_WITH_CYPHER(":set #" << id << ", cypher \"", encodedValue, "\" is present");
                return true;
            }
            else
            {
                DEBUG_WITH_CYPHER(":set #" << id << ", cypher \"", encodedValue, "\" is not present");
                return false;
            }
        }
        else
        {
            DEBUG(SET_NOT_EXIST(id));
        }
        return false;
    }

    void encstrset_copy(unsigned long src_id, unsigned long dst_id)
    {
        DEBUG("(" << src_id << ", " << dst_id << ")");
        if (setExist(src_id) && setExist(dst_id))
        {
            for (auto element : allSets[src_id].first)
            {

                if (allSets[dst_id].first.find(element) == allSets[dst_id].first.end())
                {
                    DEBUG_WITH_CYPHER(": cypher \"", element, "\" copied from set #" << src_id << " to set #" << dst_id);
                    allSets[dst_id].first.insert(element);
                }
                else
                {
                    DEBUG_WITH_CYPHER(": copied cypher \"", element, "\" was already present in set #" << dst_id);
                }
            }
        }
        if (!setExist(src_id))
        {
            DEBUG(SET_NOT_EXIST(src_id));
        }
        if (!setExist(dst_id))
        {
            DEBUG(SET_NOT_EXIST(dst_id));
        }
    }
} // namespace jnp1