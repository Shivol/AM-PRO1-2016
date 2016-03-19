//
// ������������ �7. ��������� �������.
//
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

void read_from_text( ifstream &fin, matrix a, size_t &m, size_t &n)
{
    assert(fin); // �������� �� ������������ ��������� ������

    if (!(fin >> m) || !(fin >> n))
        throw "�������� ������ �������� �����";
    if (m > MaxM || n > MaxN)
        throw "���������� ������� ������� ������ �������";

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!(fin >> a[i][j]))
                throw "�������� ������ �������� �����";

}

//
void read_from_text(const char *fname, matrix a, size_t &m, size_t &n)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

    read_from_text(fin, a, m, n);

    fin.close();
}

//
void read_from_text(ifstream &fin, double **&a, size_t &m, size_t &n)
{
    assert(fin); // �������� �� ������������ ��������� ������

    if (!(fin >> m) || !(fin >> n))
        throw "�������� ������ �������� �����";

    a = new double *[m];
    for (int i = 0; i < m; ++i) {
        a[i] = new double[n]; // ������� ������ ��� ��������� ������
        for (int j = 0; j < n; ++j)

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
void read_from_text(const char *fname, double **&a, size_t &m, size_t &n)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

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
