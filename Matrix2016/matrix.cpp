//
// Лабораторная №7. Двумерные массивы.
//
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

void read_from_text( ifstream &fin, matrix a, size_t &m, size_t &n)
{
    assert(fin); // проверка на корректность файлового потока

    if (!(fin >> m) || !(fin >> n))
        throw "Неверный формат входного файла";
    if (m > MaxM || n > MaxN)
        throw "Невозможно считать матрицу такого размера";

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!(fin >> a[i][j]))
                throw "Неверный формат входного файла";

}

//
void read_from_text(const char *fname, matrix a, size_t &m, size_t &n)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "Не найден указанный файл";

    read_from_text(fin, a, m, n);

    fin.close();
}

//
void read_from_text(ifstream &fin, double **&a, size_t &m, size_t &n)
{
    assert(fin); // проверка на корректность файлового потока

    if (!(fin >> m) || !(fin >> n))
        throw "Неверный формат входного файла";

    a = new double *[m];
    for (int i = 0; i < m; ++i) {
        a[i] = new double[n]; // ыделяем память под очередную строку
        for (int j = 0; j < n; ++j)

            if (!(fin >> a[i][j])) { // если в файле недостаточно чисел
               
                // возможны утечки памяти!                
                for (int k = 0; k <= i; ++k)
                    delete[] a[k];
                delete[] a;

                throw "Неверный формат входного файла";
            }
    }
}

//
void read_from_text(const char *fname, double **&a, size_t &m, size_t &n)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "Не найден указанный файл";

    read_from_text(fin, a, m, n);

    fin.close();
}

//
void delete_matrix(double ** const a, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; ++i)
        delete[] a[i];
    delete[] a;
}
