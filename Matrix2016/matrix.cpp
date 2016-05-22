//
// ������������ �7. ��������� �������.
//
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

void read_from_text( ifstream &fin, matrix mat, size_t &rows, size_t &cols)
{
    assert(fin); // �������� �� ������������ ��������� ������

    if (!(fin >> rows) || !(fin >> cols))
        throw "�������� ������ �������� �����";
    if (rows > MAX_ROWS || cols > MAX_COLS)
        throw "���������� ������� ������� ������ �������";

    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            if (!(fin >> mat[i][j]))
                throw "�������� ������ �������� �����";

}

//
void read_from_text(const char *fname, matrix mat, size_t &rows, size_t &cols)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

    read_from_text(fin, mat, rows, cols);

    fin.close();
}

//
void read_from_text(ifstream &fin, double **&mat, size_t &rows, size_t &cols)
{
    assert(fin); // �������� �� ������������ ��������� ������

    if (!(fin >> rows) || !(fin >> cols))
        throw "�������� ������ �������� �����";

    mat = new double *[rows];
    for (size_t i = 0; i < rows; ++i) {
        mat[i] = new double[cols]; // ������� ������ ��� ��������� ������
        for (size_t j = 0; j < cols; ++j)

            if (!(fin >> mat[i][j])) { // ���� � ����� ������������ �����
               
                // �������� ������ ������!                
                for (size_t k = 0; k <= i; ++k)
                    delete[] mat[k];
                delete[] mat;

                throw "�������� ������ �������� �����";
            }
    }
}

//
void read_from_text(const char *fname, double **&mat, size_t &rows, size_t &cols)
{
    assert(fname != nullptr);

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

    read_from_text(fin, mat, rows, cols);

    fin.close();
}

//
void delete_matrix(double ** const mat, const size_t rows, const size_t cols)
{
    assert(mat != nullptr);
    for (size_t i = 0; i < rows; ++i)
        delete[] mat[i];
    delete[] mat;
}
