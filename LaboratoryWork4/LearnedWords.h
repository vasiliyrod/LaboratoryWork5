#pragma once
#include "HashMap.h"
#include <string>
class LearnedWords : public HashMap <std::string, int>
{
public:
	LearnedWords() : HashMap< std::string, int >() {}
	LearnedWords(const HashMap<std::string, int>& x) : HashMap<std::string, int>(x){}


	int getWordsAmountRepeated(int repetetionNum) const; //�����, ����������� ����� � ������������ ���������� ������, �������� (����������) ������� ������ ��� ����� ����� �����.



};

int LearnedWords::getWordsAmountRepeated(int repetetionNum) const //�����, ����������� ����� � ������������ ���������� ������, �������� (����������) ������� ������ ��� ����� ����� �����.
{
	int wordsAmount = 0;
	for (int i = 0; i != BUCKETS_AMOUNT; ++i)
	{
		const std::list<std::pair<std::string, int>>& currBucket = buckets[i];
		for (auto pair : currBucket)
		{
			if (pair.second >= repetetionNum)
			{
				wordsAmount++;
			}
		}
	}
	return wordsAmount;
}
