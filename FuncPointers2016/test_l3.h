/* test_l3.h
 * �������� ������ ������� �� ���������� func_l3.h
 */
#pragma once

// bool test_swap()
// ��������:
// template <typename T> void swap_ptr(T *a, T*b)
// �������� ���������� ���� int, double, char*.
bool test_swap();

// bool test_exp_of()
// ��������:
// double exp_of(const double x, const double eps = precision)
// �������� ��� ������������� ���������� (0, 1), �������� ��������� ��������,
// ��������� ���������� � exp(x).
bool test_exp_of();

// bool test_sum_denominators()
// ��������:
// uint sum_denomnators(const uint k)
// �������� ��� ������������� ���������� (0, 1, 2), �������� �������� �����.
bool test_sum_prime_factors();

// ��� ������������ ������� � �������� ��������
// ������ ���������� ��������� ����������� 
// � ����������� ���������� �����������.
// �� �������������!
// bool test_tab();

// bool test_root()
// ��������:
// double root(double(*const f)(double), const double a, const double b, const double eps)
// ���������  sin [-1; 1]
//            cos [0; 2]
//            x^2 - 1 [0; 1] [-1;0] [2;0]
bool test_root();

// bool test_full_func_l3()
// ����������� ������ ���� ������ ������ ����������
bool test_full_func_l3();