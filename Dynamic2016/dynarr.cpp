//
// ������������ ������ �4. ������������ �������.
//
#include <iostream>
#include <fstream>
#include <cassert>
#include "dynarr.h"

void findZeros(const int* a, const size_t n, int &first, int &last)
{
    assert(a != nullptr);
    assert(n > 0);

    first = -1;
    last = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == 0) {
            if (first == -1) first = i;
            last = i;
        }

    if (first == -1) throw "��� ����� � �������";

    assert(first != -1);
    assert(last != -1);
}

void duplicateBetweenZeros(int *&a, size_t &n)
{
    assert(a != nullptr);
    assert(n > 0);

    int f = 0, l = 0;
    findZeros(a, n, f, l);
    if (f == l) throw "���� ���� � �������";
    if (f + 1 == l) return;  // ������ �����������

    int* b = new int[n + l - f - 1];

    for (int i = 0; i <= f; i++)
        b[i] = a[i];

    int j = f + 1;
    for (int i = j; i < l; i++, j += 2) {
        b[j] = a[i];
        b[j + 1] = a[i];
    }

    for (int i = l; i < n; i++, j++)
        b[j] = a[i];

    assert(j == n + l - f - 1);

    n += l - f - 1;
    delete[] a;
    a = b;
}

void readFromText(const char* fname, int *&a, size_t &n)
{
    assert(fname != nullptr);
    using namespace std;

    ifstream fin(fname);

    if (!fin.is_open()) throw "�� ������ ��������� ����";

    if (!(fin >> n)) // ���� ������ ������� ����� - �� �����
        throw "�������� ������ �������� �����";

    a = new int[n];
    int i = 0;
    while (i < n && fin >> a[i++]);

    // ���� ���� ��������� � ����� ������ ���������� �������
    if (i != n) {
        n = i - 1;
        // ��������� �������� ������
        int *b = new int[n];
        for (int j = 0; j < n; ++j)
            b[j] = a[j];
        // ������� ������� ������� ������

        delete[] a;
        a = b;
    }

    fin.close();
}