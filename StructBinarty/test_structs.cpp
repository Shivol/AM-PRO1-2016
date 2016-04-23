//
// ������������ �11. ���������. ��������� �����.
// teest_structs.cpp
//
#include <iostream>
#include <fstream>
#include "test_structs.h"
#include "structs.h"


bool test_number_of(const char *filename)
{
    assert(filename);
    std::fstream file(filename, std::ios::in);
    if (!file.is_open())
        throw "���������� ������� ����!";

    file.seekg(0, std::fstream::end);
    int size = int(file.tellg());
    file.close();

    // ���������� ���� � �����
    assert(number_of<uint8_t>(filename) == size);

    int number_of_ints = size / sizeof(int);
    // ���������� int � �����
    assert(number_of<int>(filename) == number_of_ints);
    
#ifdef _DEBUG
    std::cerr << "test number_of: " << "OK" << std::endl;
#endif /* _DEBUG */
    return true;
}