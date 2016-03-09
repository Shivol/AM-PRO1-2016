//
//  test_sort.cpp
//  array_sort
//
//  Created by Илья Лошкарёв on 06.03.16.
//  Copyright © 2016 Илья Лошкарёв. All rights reserved.
//


#include "test_sort.h"

#include <cassert>
#include <iostream>

using namespace std;

bool test_sort( sort_int sort )
{
    //
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int n = 10;
    sort(a, n);
    for(int i = 1; i < n; ++i)
        assert(a[i-1] <= a[i]);
    //
    for(int i = 0; i < n; i++)
        a[i] = rand();
    sort(a, n);
    for(int i = 1; i < n; ++i)
        assert(a[i-1] <= a[i]);
    
#ifdef _DEBUG
    cerr << "test sort: " << "OK" << endl;
#endif /* _DEBUG */
    return true;
}
