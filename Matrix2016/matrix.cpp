//
// Лабораторная №7. Двумерные массивы.
//
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

void read_from_text( ifstream &fin, matrix a, size_t &rows, size_t &cols)
{
    assert(fin); // проверка на корректность файлового потока

    if (!(fin >> rows) || !(fin >> cols))
        throw "Неверный формат входного файла";
    if (rows > MAX_ROWS || cols > MAX_COLS)
        throw "Невозможно считать матрицу такого размера";

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (!(fin >> a[i][j]))
                throw "Неверный формат входного файла";

}

//
void read_from_text(const char *fname, matrix a, size_t &rows, size_t &cols)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "Не найден указанный файл";

    read_from_text(fin, a, rows, cols);

    fin.close();
}

//
void read_from_text(ifstream &fin, double **&a, size_t &rows, size_t &cols)
{
    assert(fin); // проверка на корректность файлового потока

    if (!(fin >> rows) || !(fin >> cols))
        throw "Неверный формат входного файла";

    a = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        a[i] = new double[cols]; // ыделяем память под очередную строку
        for (int j = 0; j < cols; ++j)

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
void read_from_text(const char *fname, double **&a, size_t &rows, size_t &cols)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "Не найден указанный файл";

    read_from_text(fin, a, rows, cols);

    fin.close();
}

//
void delete_matrix(double ** const a, const size_t rows, const size_t cols)
{
    assert(a != nullptr);
    for (size_t i = 0; i < rows; ++i)
        delete[] a[i];
    delete[] a;
}
