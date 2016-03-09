//
//  test_sort.hpp
//  array_sort
//
//  Created by Илья Лошкарёв on 06.03.16.
//  Copyright © 2016 Илья Лошкарёв. All rights reserved.
//

#ifndef test_sort_hpp
#define test_sort_hpp
#pragma once

#include <stdlib.h>
#include "sort.h"
//объявление типа функции сортировки массива целых чисел
typedef void(* const sort_int)(int *, const size_t);

bool test_sort( sort_int sort );
#endif /* test_sort_hpp */
