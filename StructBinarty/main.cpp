//
// Лабораторная №11. Структуры. Двоичнвые файлы.
// main.cpp
//

#include <iostream>
#include "structs.h"

using namespace std;

/*
  Постчитать количество точек в файле.
*/

int main()
{
    setlocale(LC_ALL, "Russian");

    fstream file("points.dat", ios::in);    
    file.seekg(0, SEEK_END);

    cout << "Размер файла: " << file.tellg() << " байт" << endl;
    
    file.close();

    size_t count_points = number_of<point>("points.dat");
    cout << "Количество точек в файле: " << count_points << endl;

    system("pause");
    return 0;
}