//
// ������������ �11. ���������. ��������� �����.
// main.cpp
//

#include <iostream>
#include "structs.h"
#include "test_structs.h"

using namespace std;

/*
  ���������� ���������� ����� � �����.
*/

int main()
{
    setlocale(LC_ALL, "Russian");
    test_number_of("points.dat");

    // ������� ���� �� ������
    fstream file("points.dat", ios::in);
    // ������� � ����� �����
    file.seekg(0, fstream::end);
    // ������� ������� ��������� ���������
    cout << "������ �����: " << file.tellg() << " ����" << endl;
    
    file.close();

    size_t count_points = number_of<point>("points.dat");
    cout << "���������� ����� � �����: " << count_points << endl;

    system("pause");
    return 0;
}