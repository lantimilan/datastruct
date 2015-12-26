// LinkedHashmap.h
#include <utility>

template<class K, class V>
class LinkedHashMap
{
    typedef std::pair<K,V> ValueType;

    struct Entry {
        K *pk;
        V *pv;
        Entry *pred;
        Entry *succ;
    };

    const float loadFactor = 0.5;
    static int initSize;
    static Entry *head;
public:
    bool insert(const K &key, const V &val);
    ValueType& erase(const K &key);
    ValueType& operator[](const K &key);
    void clear();
    size_t size();
    // TODO: iterator
};
