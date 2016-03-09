//
//  test_sort.cpp
//  array_sort
//
//  Created by Илья Лошкарёв on 06.03.16.
//  Copyright © 2016 Илья Лошкарёв. All rights reserved.
//

#include <cassert>
#include <iostream>
#include "test_sort.h"

using namespace std;

bool test_name_sort_int( sort_int sort, char* sort_name )
{
    // переместить последний элемент в начало
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int n = 10;
    sort(a, n);
    for(int i = 1; i < n; ++i)
        assert(a[i-1] <= a[i]);

    // массив случайных чисел
    for(int i = 0; i < n; i++)
        a[i] = rand();
    sort(a, n);
    for(int i = 1; i < n; ++i)
        assert(a[i-1] <= a[i]);
    
#ifdef _DEBUG
    cerr << "test " <<sort_name<< ": "<<"OK" << endl;
#endif /* _DEBUG */
    return true;
}
