#include <iostream>
#include "assert.h"
#include "LearnedWords.h"
#include "HashMap.h"

int main()
{
    //размер коллекции, созданной конструктором по умолчанию, равен нулю;
    LearnedWords words;
    assert(words.getLength() == 0);
    


    //при добавлении и удалении нового ключа в коллекцию, реализованную на хеш-таблицах, размер коллекции изменяется на единицу;
    words.setPair("boy", 1);
    words.setPair("boy", 3);
    assert(words.getLength() == 1);
    words.deletePair("boy");
    assert(words.getLength() == 0);


    //непустая коллекция после удаления всех объектов равна коллекции, созданной при помощи конструктора по умолчанию;
    LearnedWords emptyWords;
    words.setPair("boy", 2);
    words.setPair("girl", 3);
    std::cout << "1";
    words.clear();
    std::cout << "2";
    assert(words == emptyWords);
    std::cout << "3";


    //при пересечении любой коллекции с пустой, оператор && возвращает пустую коллекцию (any && empty == empty);
    words.setPair("boy", 2);
    words.setPair("girl", 3);
    std::cout << "4";
    //LearnedWords newWords = words && emptyWords;
    std::cout << "NICE";
    assert((words && emptyWords) == emptyWords);
    std::cout << "ABOBA";

    //при пересечении одинаковых коллекций, оператор && возвращает новую коллекцию, равную любой из них (any && any == any);
    LearnedWords words2;
    words2.setPair("boy", 2);
    words2.setPair("girl", 3);
    assert((words && words2) == words);
    

    //копия непустой коллекции равна оригиналу, после вставки, удаления или изменения элемента равенство нарушается;
    LearnedWords copyWords(words);
    assert(copyWords == words);


    //непустая коллекция, сохранённая в файл, равна новой коллекции, загруженной из того же файла.
    words.saveToFile("newfile.txt");
    emptyWords.getFromFile("newfile.txt");
    assert(words == emptyWords);

    std::cout << "No errors during these tests!";
    return 0;
}