#pragma once
#include "HashMap.h"
#include <string>
class LearnedWords : HashMap <std::string, int>
{
public:
	int getWordsAmountRepeated(int repetetionNum); //�����, ����������� ����� � ������������ ���������� ������, �������� (����������) ������� ������ ��� ����� ����� �����.

};

