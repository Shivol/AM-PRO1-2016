//
// ������������ �8. �-������. ���������� cstring
// my_cstring.cpp
// 

#include <cassert>
#include <cstring>
#include <cctype>
#include "my_cstring.h"

int my_cstring::strcmp(const char *str1, const char *str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);
    // ���� ��������� ������ *str1, *str2 != 0 � *str1 == *str2
    while (*str1 && *str2 && *str1 == *str2)
        str1++, str2++;
    // �������� �������� ��� ����������� ��������
    return *str1 - *str2;
}

size_t my_cstring::word_count(const char *str)
{
    assert(str != nullptr);
    size_t count = 0;
    while (*str) {
        while ( isspace(*str)) str++;
        if (*str) count++;
        while ( isgraph(*str)) str++;
    }
    return count;
}