//
// ������������ ������ �13. ������������ ��������� ������. ������
// test_tlist.h
//

#pragma once

#include "tlist.h"

// ��������� ������-������:
// ������ �������� tlist, ������ �� �������
// ��������� �� ��������� ������� � �������.
// ��� �������� ����� ��������� 
// ������������ ���������� � �����.
typedef tlist *array_list;

// ������� ��������� �������-������ �� ������� ��������.
// ������� ���������:
//     array - ������ �������� ��������� ������;
//     length - ���������� ��������.
// ���������� ������ ��������� tlist.
array_list get_array_list(const tlist::datatype *array, size_t length);

// ���� ��� �������
// array_list get_array_list(const tlist::datatype *array, size_t length)
// ��������� ������������ ��������� �������-������ � �������� � ������.
bool test_get_array_list();

// ������� �������� �������� ������ ��� �������� �������� ������
// ������� ������:
//     filename - ��� ������������ ����� ������;
//     length - ���������� ������.
// ���������� ��������� �������� ������ � ������ �� ����� ���� 
// � �������� ������, ���������� �� �� ������.
// ���� ������� ���� �� ������, ����������� ���������� char*.
tlist::datatype *create_test_data(const char* filename, size_t length);

// ���� ��� �������
// tlist::datatype *create_test_data(const char* filename, size_t length)
// ���������� �������� � ����� � ����������� ��������.
bool test_create_test_data();

// ���� �� ��������� ������� � ������
// ������� ���������:
//     begin - ��������� �� ������ ������;
//     array - �������� �� ������� �������;
//     length - ����� �������.
// � ������ �� ���������� �������� ��������� ����������� assert.
bool is_equal_test(const tlist *begin, tlist::datatype *array, size_t length);


// ���� ��� �������
// tlist *find(const tlist *begin, const tlist::datatype x)
// ��������� ������ ������� � ���������� ��������� � ������.
bool test_find();

// ���� ���� ������� tlist.h
bool test_tlist_full();