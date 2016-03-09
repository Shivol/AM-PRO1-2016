/* test_l2.cpp
 * ���������� ������ ��� ������� ���������� func_l2.h
 */

#include <iostream>
#include <cmath>
#include <cassert>

#include "func_l2.h"
#include "test_l2.h"


using namespace std;

// �������� ��������� ������������ �����
const double precision = 1E-16;

bool test_distance()
{  

    double x1 = 0, y1 = 0;
    double x2 = 1, y2 = 0;
    double result = 1;

    // ���� 1 - ��������� �������
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);
    
    x1 = 2; y1 = 5;
    x2 = 3; y2 = 4;
    result = sqrt(2);

    // ���� 2 - ������� �������������� �����
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);
    
    x1 = -2; y1 = -5;
    x2 = -2; y2 = -5;
    result = 0;

     // ���� 3 - ������� ������� �����
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);

// �������� ������� � ������ ������� (������ _DEBUG)
#ifndef NDEBUG

    // ���� ��� ����� ������������� ������ � ������ �������
    // std::cerr - ����������� ����� ������ ��� ������
    // �� ��������� ������� �� �������    
    cerr<<"distance test: OK"<<endl;      
#endif /* NDEBUG */

    return true;
}
