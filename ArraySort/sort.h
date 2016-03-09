//
//  sort.h
//  array_sort
//
//  Created by Илья Лошкарёв on 06.03.16.
//  Copyright © 2016 Илья Лошкарёв. All rights reserved.
//

#ifndef sort_h
#define sort_h

#pragma once

#include <cassert>

//
typedef void(* const sort_int)(int *, const size_t);

//
template <typename T>
void swap( T *a, T *b)
{
    assert(a !=nullptr);
    assert(b != nullptr);

    T tmp = *b;
    *b = *a;
    *a = tmp;
}

//
void qsort(int *a, const size_t n);

//
double sort_time_in_seconds_for( sort_int sort, int* a, const size_t n);

#endif /* sort_h */
