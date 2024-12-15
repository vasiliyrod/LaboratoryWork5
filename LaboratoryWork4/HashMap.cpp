#include "HashMap.h"

template <typename keyT, typename valT>
int HashMap<keyT, valT>::hashFunction(keyT key) const
{
	std::hash <keyT> hashFunc;
	return hashFunc(key) % BUCKETS_AMOUNT;
}

template<typename keyT, typename valT>
bool HashMap<keyT, valT>::operator==(const HashMap& _hashMap) const
{
	for (int i = 0; i != BUCKETS_AMOUNT; ++i)
	{
		if (buckets[i].empty() xor _hashMap.buckets[i].empty())
		{
			return false;
		}
		else if(buckets[i].size() == _hashMap.buckets[i].size())
		{
			std::list<std::pair<keyT, valT>>::const_iterator it2 = _hashMap.buckets[i].begin();
			for (std::list<std::pair<keyT, valT>>::const_iterator it1 = buckets[i].begin(); it1 != buckets[i].end(); ++it1, ++it2 )
			{
				if (it1->first == it2->first && it1->second == it1->second)
				{
					continue;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}

template<typename keyT, typename valT>
void HashMap<keyT, valT>::setPair(keyT key, valT value)
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
	}
}

template<typename keyT, typename valT>
bool HashMap<keyT, valT>::deletePair(keyT key)
{
	bool isDeleted = false;
	int hash = hashFunction(key);
	std::list<std::pair<keyT, valT>> &currBucket = buckets[hash];

	for (std::list<std::pair<keyT, valT>>::iterator it = currBucket.begin(); it != currBucket.end();)
	{
		if (it->first == key)
		{
			currBucket.erase(it);
			isDeleted = true;
			break;
		}
		else {
			++it;
		}
	}

	return isDeleted;
}

template<typename keyT, typename valT>
valT HashMap<keyT, valT>::operator[](keyT key) const
{
	bool isDeclaired = false;
	int hash = hashFunction(key);
	const std::list<std::pair<keyT, valT>>& currBucket = buckets[hash];

	if (!currBucket.empty())
	{
		for (std::pair<keyT, valT> pair : currBucket)
		{
			if (pair.first == key)
			{
				return pair.second;
			}
		}
	}
	return valT();
}

template<typename keyT, typename valT>
bool HashMap<keyT, valT>::isDefined(keyT key) const
{
	int hash = hashFunction(key);
	for (std::pair<keyT, valT> pair : buckets[hash])
	{
		if (pair.first == key)
		{
			return true;
		}
	}
	return false;
}

template<typename keyT, typename valT>
HashMap<keyT, valT>::HashMap()
{
}

template<typename keyT, typename valT>
void HashMap<keyT, valT>::clear()
{
	for (int i = 0; i != BUCKETS_AMOUNT; ++i)
	{
		if (!buckets[i].empty())
		{
			buckets[i].clear();
		}
	}
	
}

