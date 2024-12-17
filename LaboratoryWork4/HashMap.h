#pragma once
#include<string>
#include<list>
#include<utility>
#include<iostream>
#include<fstream>


template<typename keyT, typename valT>
class HashMap
{
public:
	HashMap();
	HashMap(const HashMap &_hashMap); //  онструктор копировани€
	~HashMap();

	void clear(); // ћетод удал€ющий все хран€щиес€ значени€ из коллекции
	int getLength() const; // метод, возвращающий количество хран€щихс€ в коллекции значений;
	bool saveToFile(std::string path) const;
	bool getFromFile(std::string path);
	bool operator == (const HashMap &_hashMap) const;
	void setPair(keyT key, valT value); //метод, добавл€ющий в коллекцию заданное значение;
	bool deletePair(keyT key);
	valT operator [] (keyT key) const;
	bool isDefined(keyT key) const;
	HashMap operator && (const HashMap &_hashMap) const; // && принимает другую коллекцию и возвращает все общие значени€ T в виде новой коллекции


protected:
	int hashFunction(keyT key) const;
	
	static const int BUCKETS_AMOUNT = 100;
	std::list<std::pair<keyT, valT>> buckets[BUCKETS_AMOUNT];
}; 

template <typename keyT, typename valT>
int HashMap<keyT, valT>::hashFunction(keyT key) const
{
	std::hash<keyT> hashFunc;
	return hashFunc(key) % BUCKETS_AMOUNT;
}

template<typename keyT, typename valT>
bool HashMap<keyT, valT>::getFromFile(std::string path)
{
	std::string line;
	std::ifstream file(path);  // открываем файл дл€ чтени€
	keyT key;
	valT value;

	if (file.is_open())
	{
		try
		{
			file >> key;
			file >> value;
			for (; !file.eof();)
			{
				setPair(key, value);
				file >> key;
				if (!file.eof())
				{
					file >> value;
				}
				else
					break;
			}
		}
		catch (std::ifstream::failure& readErr)
		{
			std::cerr << "\n\nCouldn't read from file\n"
				<< readErr.what()
				<< std::endl;
			clear();
		}

	}

	file.close();
	return false;
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
		else if (buckets[i].size() == _hashMap.buckets[i].size())
		{
			std::list<std::pair<keyT, valT>> copyList2 = _hashMap.buckets[i];
			for (typename std::list<std::pair<keyT, valT>>::const_iterator it1 = buckets[i].begin(); it1 != buckets[i].end(); ++it1)
			{
				bool flag = false;
				for (auto it2 = copyList2.begin(); it2 != buckets[i].end();)
				{
					if (it1->first == it2->first && it1->second == it1->second)
					{
						flag = true;
						it2 = copyList2.erase(it2);
						break;
					}
					++it2;
				}
				if (!flag)
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
	std::list<std::pair<keyT, valT>>& currBucket = buckets[hash];

	for (typename std::list<std::pair<keyT, valT>>::iterator it = currBucket.begin(); it != currBucket.end();)
	{
		if (it->first == key)
		{
			it = currBucket.erase(it);
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
HashMap<keyT, valT> HashMap<keyT, valT>::operator&&(const HashMap& _hashMap) const
{
	HashMap<keyT, valT> newHashmap;

	for (int i = 0; i != BUCKETS_AMOUNT; ++i)
	{
		std::list<std::pair<keyT, valT>> copyList2 = _hashMap.buckets[i];
		for (typename std::list<std::pair<keyT, valT>>::const_iterator it1 = buckets[i].begin(); it1 != buckets[i].end(); ++it1)
		{
			std::cout << "6";

			for (auto it2 = copyList2.begin(); it2 != copyList2.end(); ++it2)
			{
				std::cout << "7";

				if (it1->first == it2->first && it1->second == it2->second)
				{
					newHashmap.buckets[i].push_back(std::pair<keyT, valT>(it2->first, it2->second));
					std::cout << "8";
					copyList2.erase(it2);
					std::cout << "9";

					break;
				}
			}
		}
	}

	return newHashmap;
}

template<typename keyT, typename valT>
HashMap<keyT, valT>::HashMap()
{

}

template<typename keyT, typename valT>
HashMap<keyT, valT>::HashMap(const HashMap& _hashMap)
{
	for (int i = 0; i != BUCKETS_AMOUNT; ++i)
	{
		if (!_hashMap.buckets[i].empty())
		{
			for (typename std::list<std::pair<keyT, valT>>::const_iterator it2 = _hashMap.buckets[i].begin(); it2 != buckets[i].end(); ++it2)
			{
				buckets[i].push_back(std::pair<keyT, valT>(it2->first, it2->second));
			}
		}
	}
}

template<typename keyT, typename valT>
HashMap<keyT, valT>::~HashMap()
{
	delete[] buckets;
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

template<typename keyT, typename valT>
int HashMap<keyT, valT>::getLength() const
{
	int length = 0;
	for (int i = 0; i != BUCKETS_AMOUNT; ++i)
	{
		if (!buckets[i].empty())
		{
			for (typename std::list<std::pair<keyT, valT>>::const_iterator it1 = buckets[i].begin(); it1 != buckets[i].end(); ++it1)
			{
				length++;
			}
		}
	}
	return length;
}

template<typename keyT, typename valT>
bool HashMap<keyT, valT>::saveToFile(std::string path) const
{
	std::string line;
	std::ofstream file(path);  // открываем файл дл€ записи
	keyT key;
	valT value;
	int hash;
	if (file.is_open())
	{
		try
		{
			for (int i = 0; i != BUCKETS_AMOUNT; ++i)
			{
				hash = hashFunction(key);
				const std::list<std::pair<keyT, valT>>& currBucket = buckets[hash];

				if (!currBucket.empty())
				{
					for (auto pair : currBucket)
					{
						file << pair.first << ' ' << pair.second << std::endl;
					}
				}
			}
		}
		catch (std::ofstream::failure& writeErr)
		{
			std::cerr << "\n\nException occured when writing to a file\n"
				<< writeErr.what()
				<< std::endl;
		}
	}
	file.close();
	return false;
}
