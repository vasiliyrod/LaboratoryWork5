#include "LearnedWords.h"

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
