//
// ������������ ������ �4. ������������ �������.
//
#include <iostream>
#include <fstream>
#include <cassert>
#include "dynarr.h"

void find_zeros(const int* array, const size_t size, size_t &first, size_t &last)
{
    assert(array != nullptr);
    assert(size > 0);

    first = -1;
    last = -1;
    for (size_t i = 0; i < size; i++)
        if (array[i] == 0) {
            if (first == -1) first = i;
            last = i;
        }

    if (first == -1) throw "��� ����� � �������";

    assert(first != -1);
    assert(last != -1);
}

void duplicate_between_zeros(int *&array, size_t &size)
{
    assert(array != nullptr);
    assert(size > 0);

    size_t f = 0, l = 0;
    find_zeros(array, size, f, l);
    if (f == l) throw "���� ���� � �������";
    if (f + 1 == l) return;  // ������ �����������

    int* b = new int[size + l - f - 1];

    for (size_t i = 0; i <= f; i++)
        b[i] = array[i];

    int j = f + 1;
    for (size_t i = j; i < l; i++, j += 2) {
        b[j] = array[i];
        b[j + 1] = array[i];
    }

    for (size_t i = l; i < size; i++, j++)
        b[j] = array[i];

    assert(j == size + l - f - 1);

    size += l - f - 1;
    delete[] array;
    array = b;
}

void read_from_text(const char* fname, int *&array, size_t &size)
{
    assert(fname != nullptr);
    using namespace std;

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

    if (!(fin >> size)) // ���� ������ ������� ����� - �� �����
        throw "�������� ������ �������� �����";

    array = new int[size];
    size_t i = 0;
    while (i < size && fin >> array[i++]);

    // ���� ���� ��������� � ����� ������ ���������� �������
    if (i != size) {
        size = i - 1;
        // ��������� �������� ������
        int *b = new int[size];
        for (size_t j = 0; j < size; ++j)
            b[j] = array[j];
        // ������� ������� ������� ������

        delete[] array;
        array = b;
    }

    fin.close();
}