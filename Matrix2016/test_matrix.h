//
// ������������ ������ �7. ��������� �������
// test_matrix.h
//
// ����� ������� matrix.cpp

#pragma once

#include <iostream>
#include <fstream>
#include "matrix.h"

// ������������ ������� �������:
// template <typename T> 
// bool is_equal(const T a, const T b, const size_t m, const size_t n, const double precision = 0.0)
// ������� ������:
//     fname - ��� ����� � ��������� �������.
// ���� �������� ������ ������ ��������� ��� ������� ��� �������.
bool test_is_equal(const char* fname);