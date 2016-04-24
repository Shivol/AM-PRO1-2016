//
// ������������ ������ �12. ��������� � ������������ ������
// structs_dynamic.h 
//
#pragma once
#include <cstdint>
#include <iostream>
#include <string>


// ������ � ��������:
//     fullname - ���;
//     course - ����� �����;
//     group - ����� ������;
//     credits - ������ �� ������������.
struct student
{
    // ���������� �������� �����
    static const size_t name_size = 128;
    // ���������� ������������ �����
    static const size_t assign_count = 10;

    char fullname[name_size];
    uint16_t course, group;
    uint16_t credits[assign_count];
};


// ���������� ���������� ����� ��������.
// ������� ������:
//     stud - ������ �� ������ ��������.
// ���������� ���������� ���� ��������.
uint32_t credits_sum(const student &stud);


// ������ ������ �������� �� ������.
// ������� ������:
//     s - ������ ���������� ������ ��������,
//     ���� ����������� ��������� ���������.
// ��������� ����������� ���������.
// � ������ ������������ ������, ����������� ���������� char*
student get_student(const std::string &s);

// ����� ������ �������� � cout.
// ������� ������:
//     stud - ������ �� ������ ��������.
void print_student(const student &stud);

// ������ ������ �� ���������� ����� � ������ � �������� ���� ���� student.
// ������� ���������:
//     filename - ��� ����� ������.
// � ���������� ������ ���� � ������ filename.dat,
// ���������� ������ ��������� �� �������� �����.
// � ������ ������� � �������� � ������, ����������� ���������� char*
void binary_from_text(const char *filename);