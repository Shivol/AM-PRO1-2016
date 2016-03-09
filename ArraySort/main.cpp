//
// Лабораторная №5. Сортировкии, рекурсия в массивах.
// main.cpp
//
// Замер времени выполнения функции быстрой сортировки.

#include <iomanip>
#include <iostream>
#include "test_sort.h"
#include "sort_time.h"

int main(int argc, const char * argv[]) {
    test_sort_int(qsort);

    const int n = 100000;
    // массив большего размера может не поместиться на стеке,
    // в этом случае его прийдётся разместить в динамической памяти:
    // int *a = new int[n];
    int a[n];
    
    for (int i = 0; i < n; ++i)
        a[i] = rand();

    double sec = sort_time_in_seconds_for(qsort, a, n);
    

    // Форматированный вывод:
    std::cout << std::fixed;
    // фиксированный формат чисел с плавающей точкой
    std::cout.precision(4);
    // задание количества знаков после запятой
    std::cout << std::setw(10) << "N" << " | " << "T" << std::endl;
    // установка ширины поля вывода для следующего аргумента
    
    std::cout << std::setw(10) << n << " | " << sec << std::endl;

    system("pause");
    return 0;
}
