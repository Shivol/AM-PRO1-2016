//
// ������������ �8. �-������. ���������� cstring
// my_cstring.h
// 

#pragma once

// ����� ������� ������������ �� ������ 
// � ��������� ������������ ����������.

// ������� ����������� ������������ ���.
namespace my_cstring
{
    // ������������ ����� ����������� ������
    const size_t Max_Len = 256;

    // ������� ��������� �����.
    // ������� ���������:
    //     str1 - ������ ������ ������;
    //     str2 - ������ ������ ������.
    // ���������:
    //      0 - ������ �����;
    //     >0 - ������ ��������� ������ ������ 1 > ������ 2;
    //     <0 - ������ ��������� ������ ������ 1 < ������ 2.
    int strcmp(const char *str1, const char *str2);


    size_t word_count(const char* str);

}