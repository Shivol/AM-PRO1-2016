//
// ������������ ������ �4. ������������ �������.
// dynarrdbg.cpp
//
// ��� ������ ����� �����. �������������� � ������� ��� ��������, ����������� 
// ����� ������ � ��������� �������� ����������. ���� ������� ����������, ������ 
// ��������������� ���������.

#include "crtdynmem.h"
#include "dynarr.h"
#include "test_dynarr.h"
#include <iostream>


using namespace std;


int main()
{
    test_dynarr_full();
    setlocale(LC_ALL, "Rus");
    cout << "������� ��� �����: ";
    char fname[20];
    cin >> fname;

   
    int *a = nullptr;  // ������������ ���������� ��� ���������� � ����� �������� ������� 
    size_t n = 0;

    // C����� ����� ������� 
    // ��� ����� ����������� ���������� ������
    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

    try {
        read_from_text(fname, a, n);
        duplicate_between_zeros(a, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    catch (char* c) {
        cout << c << endl;
    }

    //delete [] a;   

    // ������ � �� ����������� ������������ ������!     
     
     // ������� ��� ������ ������ �� ������� ������
     // _CrtDumpMemoryLeaks();

     // ������� ��� ������ ������ � ������ �������
     _CrtMemDumpAllObjectsSince(&_ms);

    system("pause");
    return 0;
}