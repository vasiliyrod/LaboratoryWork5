#pragma once
#include "HashMap.h"
#include <string>
class LearnedWords : public HashMap <std::string, int>
{
public:
	int getWordsAmountRepeated(int repetetionNum) const; //�����, ����������� ����� � ������������ ���������� ������, �������� (����������) ������� ������ ��� ����� ����� �����.

};
