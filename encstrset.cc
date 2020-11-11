#include "encstrset.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define SET_NOT_EXIST(x) ": set #" << x << " does not exist"

#define STRING_OR_NULL(x) (x == nullptr ? "NULL" : "\"" + string(x) + "\"")

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

#ifdef DNDEBUG
    const bool debug = false;
#else
    const bool debug = true;
#endif

    using encodedString = string;
    using SetNumber = unsigned long;
    using StrSet = unordered_set<encodedString>;
    using Sets = unordered_map<SetNumber, StrSet>;

    const unsigned long startingSetNumber = 0;
    unsigned long nextSetNumber = startingSetNumber;

    Sets &allSets()
    {
        static Sets *sets = new Sets();
        return *sets;
    }

    bool setExist(Sets::iterator setIterator)
    {
        return setIterator != allSets().end();
    }

    StrSet &getSetReference(Sets::iterator setIterator)
    {
        return setIterator->second;
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
        allSets()[nextSetNumber] = newSet;
        DEBUG(": set #" << nextSetNumber << " created");
        return nextSetNumber++;
    }

    void encstrset_clear(unsigned long id)
    {
        DEBUG("(" << id << ")");
        auto setIterator = allSets().find(id);
        if (setExist(setIterator))
        {
            getSetReference(setIterator).clear();
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
        auto setIterator = allSets().find(id);
        if (setExist(setIterator))
        {
            allSets().erase(setIterator);
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
        auto setIterator = allSets().find(id);
        if (setExist(setIterator))
        {
            DEBUG(": set #" << id << " contains " << getSetReference(setIterator).size() << " element(s)");
            return getSetReference(setIterator).size();
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
        auto setIterator = allSets().find(id);
        if (setExist(setIterator))
        {
            string encodedValue = encode(value, key);
            if (getSetReference(setIterator).find(encodedValue) ==
                getSetReference(setIterator).end())
            {
                getSetReference(setIterator).insert(encodedValue);
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
        auto setIterator = allSets().find(id);
        if (setExist(setIterator))
        {
            string encodedValue = encode(value, key);
            auto encodedValueIterator = getSetReference(setIterator).find(encodedValue);
            if (encodedValueIterator != getSetReference(setIterator).end())
            {
                DEBUG_WITH_CYPHER(":set #" << id << ", cypher \"", encodedValue, "\" removed");
                getSetReference(setIterator).erase(encodedValueIterator);
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
        auto setIterator = allSets().find(id);
        if (setExist(setIterator))
        {
            string encodedValue = encode(value, key);
            if (getSetReference(setIterator).find(encodedValue) !=
                getSetReference(setIterator).end())
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
        auto srcSetIterator = allSets().find(src_id);
        auto dstSetIterator = allSets().find(dst_id);
        if (setExist(srcSetIterator) && setExist(dstSetIterator))
        {

            for (auto element : getSetReference(srcSetIterator))
            {

                if (getSetReference(dstSetIterator).find(element) ==
                    getSetReference(dstSetIterator).end())
                {
                    DEBUG_WITH_CYPHER(": cypher \"", element, "\" copied from set #" << src_id << " to set #" << dst_id);
                    getSetReference(dstSetIterator).insert(element);
                }
                else
                {
                    DEBUG_WITH_CYPHER(": copied cypher \"", element, "\" was already present in set #" << dst_id);
                }
            }
        }
        if (!setExist(srcSetIterator))
        {
            DEBUG(SET_NOT_EXIST(src_id));
        }
        if (!setExist(dstSetIterator))
        {
            DEBUG(SET_NOT_EXIST(dst_id));
        }
    }
} // namespace jnp1