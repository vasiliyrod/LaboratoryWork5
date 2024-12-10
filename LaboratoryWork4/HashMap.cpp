#include "HashMap.h"

template <class keyT, class valT>
int HashMap<keyT, valT>::hashFunction(keyT key)
{
	std::hash <keyT> hashFunc;
	return hashFunc(key) % BUCKETS_AMOUNT;
}

template<class keyT, class valT>
inline void HashMap<keyT, valT>::setPair(keyT key, valT value)
{
	bool isDeclaired = false;
	int hash = hashFunction(key);
	for (std::pair<keyT, valT> pair : buckets[hash])
	{
		if (pair.first == key)
		{
			pair.second = value;
			isDeclaired = true;
			break;
		}
	}
	if (!isDeclaired)
	{
		buckets[hash].push_back(std::pair<keyT, valT>(key, value));
		length++;
	}
}

