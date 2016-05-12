//
// ������������ �7. ��������� �������.
//
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

void read_from_text( ifstream &fin, matrix a, size_t &rows, size_t &cols)
{
    assert(fin); // �������� �� ������������ ��������� ������

    if (!(fin >> rows) || !(fin >> cols))
        throw "�������� ������ �������� �����";
    if (rows > MAX_ROWS || cols > MAX_COLS)
        throw "���������� ������� ������� ������ �������";

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (!(fin >> a[i][j]))
                throw "�������� ������ �������� �����";

}

//
void read_from_text(const char *fname, matrix a, size_t &rows, size_t &cols)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

    read_from_text(fin, a, rows, cols);

    fin.close();
}

//
void read_from_text(ifstream &fin, double **&a, size_t &rows, size_t &cols)
{
    assert(fin); // �������� �� ������������ ��������� ������

    if (!(fin >> rows) || !(fin >> cols))
        throw "�������� ������ �������� �����";

    a = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        a[i] = new double[cols]; // ������� ������ ��� ��������� ������
        for (int j = 0; j < cols; ++j)

            if (!(fin >> a[i][j])) { // ���� � ����� ������������ �����
               
                // �������� ������ ������!                
                for (int k = 0; k <= i; ++k)
                    delete[] a[k];
                delete[] a;

                throw "�������� ������ �������� �����";
            }
    }
}

//
void read_from_text(const char *fname, double **&a, size_t &rows, size_t &cols)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

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
