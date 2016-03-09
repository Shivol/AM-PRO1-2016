//
// Лабораторная раббота №3. Массивы, обработка массивов.
// test_array.cpp
//
#include <cassert>
#include <iostream>
#include "array.h"
#include "test_array.h"

using namespace std;
//
bool test_product_positive_after_zero()
{
    int a[] = { 1, 0, 7, -1, 2, -3, 5 };
    int n = 7;
    int result = 70;
    assert(product_positive_after_zero(a, n) == result);

    a[0] = 0; a[1] = 1;
    //{ 0, 1, 7, -1, 2, -3, 5}
    //проверка c первым нолем
    assert(product_positive_after_zero(a, n) == result);

    a[0] = 5;
    a[6] = 0;
    //{ 5, 1, 7, -1, 2, -3, 0}
    //последний ноль    
    assert(product_positive_after_zero(a, n) == 0);

    a[6] = -1;
    //{ 5, 1, 7, -1, 2, -3, -1}
    //ошибка - нет ноля
    try {
        product_positive_after_zero(a, n);
        assert(0);
    }
    catch (char *c) {
        assert(c);
    }
#ifndef _DEBUG
    cerr << "test product_positive_after_zero : OK" << endl;
#endif /* _DEBUG */
    return true;
}
