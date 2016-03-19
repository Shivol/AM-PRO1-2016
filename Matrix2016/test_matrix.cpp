//
// Лабораторная раюота №7. Двумерные массивы
// test_matrix.cpp
//
// Тесты функций matrix.cpp

#include <cassert>
#include <iostream>
#include <fstream>
#include "matrix.h"
#include "test_matrix.h"

using namespace std;

bool test_is_equal(const char* fname)
{
    // равенство статических матриц
    matrix a, b;
    size_t ma, na, mb, nb;

    read_from_text(fname, a, ma, na);
    read_from_text(fname, b, mb, nb);

    assert(is_equal(a, b, ma, na));

    // равенство динамических матриц
    double **aa = nullptr, **bb = nullptr;

    read_from_text(fname, aa, ma, na);
    read_from_text(fname, bb, mb, nb);

    assert(is_equal(aa, bb, ma, na));

    delete_matrix(aa, ma, na);
    delete_matrix(bb, mb, nb);

    // не равенство статических матриц
    ifstream fin(fname); 
       
    read_from_text(fin, a, ma, na);
    read_from_text(fin, b, mb, nb);

    assert(ma == mb && na == nb);
    assert(!is_equal(a, b, ma, na));

    fin.close();

    // не равенство динамических матриц
    fin.open(fname);

    read_from_text(fin, aa, ma, na);
    read_from_text(fin, bb, mb, nb);

    assert(ma == mb && na == nb);
    assert(!is_equal(aa, bb, ma, na));

    delete_matrix(aa, ma, na);
    delete_matrix(bb, mb, nb);
    fin.close();

#ifndef NDEBUG
    cerr << "test is_equal : OK" << endl;
#endif /* NDEBUG */
    return true;
}