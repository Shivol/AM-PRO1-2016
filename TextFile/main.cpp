//
// Лабораторная работа №10. Текстовые файлы
// main.cpp
//
#include <iostream>
#include <fstream>
#include "test_text.h"
#include "text.h"

int main()
{    
    try {
        test_full_text();
        print_len("jabberwocky.txt");
    }
    catch (char *c) {
        std::cout << c << std::endl;
    }
    system("pause");
    return 0;
}