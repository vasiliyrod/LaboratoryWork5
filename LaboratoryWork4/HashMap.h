#pragma once
#include<string>
#include<list>
#include<utility>


template<typename keyT, typename valT>
class HashMap
{
public:
	HashMap();
	HashMap(const HashMap &_hashmap); //  онструктор копировани€
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

	static const int BUCKETS_AMOUNT = 10000;
	std::list<std::pair<keyT, valT>> buckets[BUCKETS_AMOUNT];
}; 
