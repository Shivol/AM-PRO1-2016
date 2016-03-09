/* func_l3.h
 * �������� ������� � ������������ ������ �3.
 */
#pragma once
#include <cassert>

/* ���������� ��������� : �������� ����������,
 * ����� �������� �� ���� ������, ������������ ������ ���������.
 */
const double precision = 1E-16;

/* ����������� ����������������� ���� uint,
 * ��� ���������������� ������ �����.
 * (����������� int ������� �� ����������� �������)
 */
typedef unsigned int uint;

// void swap_ptr (T *a, T *b)
// ������ ������� ������ ���������� ���� ���������� �� ���������
// ���������:
//      a, b - ��������� �� ����������.
// ���������:
//      ��������� a � b  �������� ���������.
template <typename T>
void swap_ptr(T *a, T *b)
{
    assert(a != nullptr);
    assert(b != nullptr);
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

// double exp_of(const double x, const double eps = precision);
// ���������� �������� ���������� � �������� ���������.
// ���������:
//      x - �������� ��������� �������,
//      eps - �������� ���������� (�� ��������� = precision).
// ���������:
//      �������� e(x) � ��������� eps.
double exp_of(const double x, const double eps = precision);

// uint sum_prime_factors(const uint k);
// ���������� ����� ������� ��������� ������ ����� � ������� ��������.
// ���������:
//      k - ��������������� ����� �����.
// ���������:
//      ����� ������� ��������� ����� k.
uint sum_prime_factors(const uint k);

// void tab(double(* const f)(double), const double a, const double b, const double h);
// ����� ���� �������� ������� �� ������� [a;b] � ����� h
// ���������:
//      f - ��������� �� ������� �������,
//      a, b - ������� �������,
//      h - ��� ��������� (�� ��������� = precision).
// ���������:
//      ����� �������� ������� � ����: x | f(x)
//      ��� x = {a, a+h, a+2h, ... b} 
//      �� ����������� �����.
void tab( double(* const f)(double), const double a, const double b, const double h = precision);

// double root(double(*const f)(double), const double a, const double b, const double eps)
// ����� ����� ������� �� ������� [a;b] � ��������� eps ������� ������� �������.
// ���������:
//      f - ��������� �� ������� �������,
//      a, b - ������� ������� (f(a)*f(b) < 0),
//      eps - �������� ������ (�� ��������� = precision).
// ���������:
//      �������� ����� ������� �� �������.
double root(double(*const f)(double), const double a, const double b, const double eps = precision);