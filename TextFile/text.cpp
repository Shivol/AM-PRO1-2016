//
// Лабораторная работа №10. Текстовые файлы
// text.cpp
//

#include <cassert>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

#include "text.h"

using namespace std;

//
void print_len(const char *filename)
{
    assert(filename);

    // создаём файловый поток
    ifstream fin(filename);
    // проверяем, что учпешно связали поток с файлом
    if(!fin.is_open())
        throw "Couldn't open file!";

    string line;
    // пока не конец файла
    while(!fin.eof())
    {
        //читаем одну строку в память
        getline(fin,line);
        cout << line << " : " << line.length() << endl;
    }
    // завершаем работу с файлом
    fin.close();
}

//
bool is_equal_text(const char *filename1, const char *filename2)
{
    assert(filename1);
    assert(filename2);

    ifstream f1(filename1);
    if (!f1.is_open()) {
        char error[128] = "Couldn't open file ";
        strcat_s(error, 128, filename1);
        throw error;
    }

    ifstream f2(filename2);
    if (!f2.is_open()) {
        char error[128] = "Couldn't open file ";
        strcat_s(error, 128, filename2);
        throw error;
    }
    
    while (!f1.eof() && !f2.eof())
        if(f1.get() != f2.get())
            return false;

    if(!f1.eof() || !f2.eof())
        return false;
    
    f1.close();
    f2.close();
    return true;
}