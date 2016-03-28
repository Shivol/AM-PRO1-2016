//
// Лабораторная №8. С-строки. Библиотека cstring
// test_my_cstring.cpp
// 

#include <cassert>
#include <cstring>
#include <iostream>
#include "my_cstring.h"
#include "test_my_cstring.h"


bool my_cstring::test_strcmp()
{
    using my_cstring::strcmp;

    char *str1 = "Hello,world!";

    assert(strcmp(str1, str1) == 0);

    char *str2 = "World, hello!";

    assert(strcmp(str1, str2) < 0);

    assert(strcmp(str2, str1) > 0);

    str2 = "Hello, world!!!";

    assert(strcmp(str1, str2) * std::strcmp(str1, str2) >= 0);

#ifndef NDEBUG
    std::cerr << "test_strcmp: " << "OK" << std::endl;
#endif /*NDEBUG*/
    return true;
}


bool my_cstring::test_word_count()
{
    using my_cstring::word_count;

    char *str = "";
    assert(word_count(str) == 0);
    str = "    ";
    assert(word_count(str) == 0);

    str = "Hello,world!";
    assert(word_count(str) == 1);

    str = "Hello, world!";
    assert(word_count(str) == 2);
    str = "Hello,   world!";
    assert(word_count(str) == 2);
    str = "Hello,   world!  ";
    assert(word_count(str) == 2);
    str = "  Hello,   world!";
    assert(word_count(str) == 2);
    str = "  Hello,   world!  ";
    assert(word_count(str) == 2);
    str = "  H e l l o ,   w o r l d !  ";
    assert(word_count(str) == 12);
#ifndef NDEBUG
    std::cerr << "test_word_count: " << "OK" << std::endl;
#endif /*NDEBUG*/
    return true;
}

bool my_cstring::test_my_cstring()
{
    return test_strcmp() && test_word_count();
}