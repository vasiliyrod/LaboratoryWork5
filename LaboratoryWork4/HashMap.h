#pragma once
#include<string>
#include<list>
#include<utility>


template<typename keyT, typename valT>
class HashMap
{
public:
	HashMap();
	HashMap(const HashMap &_hashmap); // ����������� �����������
	~HashMap();

	void clear(); // ����� ��������� ��� ���������� �������� �� ���������
	int getLength() const; // �����, ������������ ���������� ���������� � ��������� ��������;
	bool saveToFile(std::string path) const;
	bool getFromFile(std::string path);
	bool operator == (const HashMap &_hashMap) const;
	void setPair(keyT key, valT value); //�����, ����������� � ��������� �������� ��������;
	bool deletePair(keyT key);
	valT operator [] (keyT key) const;
	bool isDefined(keyT key) const;
	HashMap operator && (const HashMap &_hashMap) const; // && ��������� ������ ��������� � ���������� ��� ����� �������� T � ���� ����� ���������


protected:
	int hashFunction(keyT key) const;

	static const int BUCKETS_AMOUNT = 10000;
	std::list<std::pair<keyT, valT>> buckets[BUCKETS_AMOUNT];
}; 
