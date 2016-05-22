//
// Ћабораторна€ работа є2. Ѕиблиотека функций
// test_l2.cpp
//

#include <iostream>
#include <cmath>
#include <cassert>

#include "func_l2.h"
#include "test_l2.h"

using namespace std;

bool test_sqr(int number_of_tests)
{
    for (int i = 0; i < number_of_tests; i++) {
        double a = rand() * (0.5 - (double)rand() / RAND_MAX);
        double result = a*a;
        assert(fabs(sqr(a) - result) < precision);
    }

    // ѕроверка запуска в режиме отладки (макрос _DEBUG)
#ifdef _DEBUG

    // Ётот код будет скомпилирован только в режиме отладки
    // std::cerr - стандартный поток вывода дл€ ошибок
    // по умолчанию выводит на консоль    
    cerr << "test sqr: OK" << endl;
#endif /* _DEBUG */

    return true;
}


bool test_distance()
{  

    double x1 = 0, y1 = 0;
    double x2 = 1, y2 = 0;
    double result = 1;

    // “ест 1 - единичный отрезок
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);
    
    x1 = 2; y1 = 5;
    x2 = 3; y2 = 4;
    result = sqrt(2);

    // “ест 2 - отрезок иррациональной длины
    assert ( abs ( distance (x1,y1,x2,y2) - result) < precision);

    // “ест 3 - отрезок нулевой длины
    // ќпишите тест дл€ отрезка нулевой длины
    assert (0);

// ѕроверка запуска в режиме отладки (макрос _DEBUG)
#ifdef _DEBUG

    // Ётот код будет скомпилирован только в режиме отладки
    // std::cerr - стандартный поток вывода дл€ ошибок
    // по умолчанию выводит на консоль    
    cerr << "test distance: OK" << endl;
#endif /* _DEBUG */

    return true;
}

bool test_full_func_l2()
{
    int number_of_tests = 100;
    return test_sqr(number_of_tests) && test_distance();
}
