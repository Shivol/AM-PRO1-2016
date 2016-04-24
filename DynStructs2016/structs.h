//
// ������������ �11. ���������. ��������� �����.
// structs.h
//
#pragma once

#include <cassert>
#include <fstream>

// ����� �� ��������� 
// (x,y)
struct point
{
    double x, y;
};

// ����������� ����
// day. month. year
struct date
{
    uint16_t day, month, year;
};

// ������ � ��������:
//     fullname - ���;
//     birthday - ���� ��������;
//     gender - ���.
struct person
{
    char fullName[128];
    date birthday;
    char gender;
};


// ��������� ������� ������ �� ����� ������ � �������� �����.
// ������� ���������:
//     fin - ����� ������ �� ����� (������ ���� ������ c ios::binary)
// ���������� �������� ������� ���� T, �������� �� �����.
// ���� ������ �� �������, fin.good() == false.
template <typename T>
T read_binary(std::ifstream &fin)
{
    T t;
    fin.read(reinterpret_cast<char*> (&t), sizeof(t));
    return t;
}

// ��������� ������� ������ � ���� ������ � �������� �����.
// ������� ���������:
//     fout - ����� ������ � ���� (������ ���� ������ c ios::binary);
//     t - ������ �� ������������ �������.
// ���� ������ �� �������, fout.good() == false.
template <typename T>
void write_binary(std::ofstream &fout, T &t)
{
    fout.write(reinterpret_cast<char*> (&t), sizeof(t));
}

// ��������� ������� �������� ���������� ��������� ��������� ���� � �����.
// ������� ���������:
//     filename - ��� ����� ������.
// ���������� ���������� ��������� ���� � � �����.
// ���� ���� �� ������� �������, ����������� ���������� char*.
template <typename T>
size_t number_of(const char *filename)
{
    assert(filename);

    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open())
        throw "���������� ������� ����!";

    size_t count = 0;
    while (!fin.eof()) {
        // ������� ��������� ������� �� �����
        read_binary<T>(fin);
        if (fin.good())   // ���� ������ ������ �������
            count++;
    }

    fin.close();
    return count;
}

