//
// ������������ �8. �-������. ���������� cstring
// main.cpp
// 
// ��������� ���������� ���� � ������.

#include <iostream>
#include "my_cstring.h"
#include "test_my_cstring.h"

using namespace std;
using namespace my_cstring;

int main()
{
    test_my_cstring();
    setlocale(LC_ALL, "Rus");

    char str[Max_Len];
    
    cout << "������� ������: ";
    
    cin.getline(str, Max_Len);

    cout << "������� ����: " << word_count(str) << endl;

    system("pause");
    return 0;
}