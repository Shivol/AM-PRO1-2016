//
// Лабораторная работа №4. Динамические массивы.
//

#include <cassert>
#include <iostream>

#include "dynarr.h"
#include "test_dynarr.h"

using namespace std;


bool test_find_zeros()
{
    // один ноль
    int a[] = { 1,0,1 };
    size_t fresult = 1, lresult = 1;
    size_t f, l;
    find_zeros(a, 3, f, l);
    assert(f == fresult && l == lresult);

    // все ноли
    int b[] = { 0,0,0,0,0,0 };
    fresult = 0;
    lresult = 5;
    find_zeros(b, 6, f, l);
    assert(f == fresult && l == lresult);

    // два разных
    int с[] = { 1,0,1,1,0,1 };
    fresult = 1;
    lresult = 4;
    find_zeros(b, 6, f, l);
    assert(f == fresult && l == lresult);

    // нет нолей
    int d[] = { 1,2,3,4,5 };
    try {
        find_zeros(d, 5, f, l);
        assert(0);
    }
    catch (char *c) {
        assert(c);
    }
#ifndef _DEBUG
    cerr << "test_find_zeros: " << "OK" << endl;
#endif 
    return true;
}

bool test_duplicate_between_zeros()
{
    {
        size_t n = 5;
        int *a = new int[5] { 1,0,1,0,1 };
        int result[] = { 1,0,1,1,0,1 };
        duplicate_between_zeros(a, n);
        assert(n == 6);
        for (size_t i = 0; i < n; i++)
            assert(a[i] == result[i]);
        delete[] a;
    } {
        size_t n = 7;
        int *a = new int[7] { 1,0,1,1,1,0,1 };
        int result[] = { 1,0,1,1,1,1,1,1,0,1 };
        duplicate_between_zeros(a, n);
        assert(n == 10);
        for (size_t i = 0; i < n; i++)
            assert(a[i] == result[i]);
        delete[] a;
    } {
        size_t n = 7;
        int *a = new int[7] { 1,0,1,0,1,0,1 };
        int result[] = { 1,0,1,1,0,0,1,1,0,1 };
        duplicate_between_zeros(a, n);
        assert(n == 10);
        for (size_t i = 0; i < n; i++)
            assert(a[i] == result[i]);
        delete[] a;
    }
#ifndef _DEBUG
    cerr << "test_duplicate_between_zeros: " << "OK" << endl;
#endif 
    return true;
}

bool test_dynarr_full()
{
    return test_duplicate_between_zeros() &&
        test_find_zeros();
}