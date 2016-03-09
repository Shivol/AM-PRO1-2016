//
// ������������ ������� �3. �������, ��������� ��������.
//
// ��������� ������������ ������������� ��������� �������, 
// ��������� ����� ������� �������� ��������. 
// ���� �� �����-���� ������� ��������� ������������ �� �������, 
// ������ ��������� �� ����.

#include <iostream>
#include "array.h"
#include "test_array.h"
using namespace std;

int main()
{
#ifndef _DEBUG
    test_product_positive_after_zero();
#endif

    setlocale(LC_ALL, "Rus");    
    int a[max_N];
    int n;
    cout<<"������� ������ ����� �����, ���������� ����"<<endl;

    getArray(a,n);
    printArray(a,n);

    try {
        cout<< "������������ ��������� ����� ������� ���� = "
            << product_positive_after_zero( a, n ) << endl;
    } catch ( char *c) {
        cout<<c<<endl;
    }

    system("pause");
    return 0;
}
