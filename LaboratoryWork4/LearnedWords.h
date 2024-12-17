#pragma once
#include "HashMap.h"
#include <string>
class LearnedWords : public HashMap <std::string, int>
{
public:
	int getWordsAmountRepeated(int repetetionNum) const; //метод, принимающий число и возвращающий количество ключей, значения (повторения) которых больше или равны этому числу.

};
