//
// Лабораторная №11. Структуры. Двоичнвые файлы.
// teest_structs.cpp
//
#include <iostream>
#include <fstream>
#include "test_structs.h"
#include "structs.h"


bool test_number_of(const char *filename)
{
    assert(filename);
    std::fstream file(filename, std::ios::in);
    if (!file.is_open())
        throw "Невозможно открыть файл!";

    file.seekg(0, std::fstream::end);
    int size = int(file.tellg());
    file.close();

    // количество байт в файле
    assert(number_of<uint8_t>(filename) == size);

    int number_of_ints = size / sizeof(int);
    // количество int в файле
    assert(number_of<int>(filename) == number_of_ints);
    
#ifdef _DEBUG
    std::cerr << "test number_of: " << "OK" << std::endl;
#endif /* _DEBUG */
    return true;
}