//
// Лабораторная №11. Структуры. Двоичнвые файлы.
// main.cpp
//

#include <iostream>
#include "structs.h"
#include "test_structs.h"

using namespace std;

/*
  Постчитать количество точек в файле.
*/

int main()
{
    setlocale(LC_ALL, "Russian");
    test_number_of("points.dat");

    // откроем файл на чтение
    fstream file("points.dat", ios::in);
    // перейдём в конец файла
    file.seekg(0, fstream::end);
    // выведем позицию файлового указателя
    cout << "Размер файла: " << file.tellg() << " байт" << endl;
    
    file.close();

    size_t count_points = number_of<point>("points.dat");
    cout << "Количество точек в файле: " << count_points << endl;

    system("pause");
    return 0;
}