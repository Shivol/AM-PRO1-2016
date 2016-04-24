//
// Лабораторная работа №12. Структуры в динамической памяти
// main.cpp
//
#include <iostream>
#include "structs.h"
#include "structs_dynamic.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    try {
        binary_from_text("students.txt");
        cout << number_of<student>("students.dat") << endl;
    }
    catch (char *error) {
        cout << error << endl;
    }
    system("pause");
    return 0;
}