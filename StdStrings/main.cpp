//
// ������������ ������ �9. ��������� �����
//

#include <iostream>
#include <crtdbg.h>
#include <windows.h>  // ��� ������������� ��������� � �������

#include "rstring.h"
#include "test_rstring.h"

using namespace std;

int main()
{
    // ��� ����� ��������� � Windows 
    // ���������� ��������� ��������� 
    // �������������� �����������

    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    test_rstring_full();

    const int MaxChars = 100;
    char str[MaxChars];
    char sub[MaxChars];
    char rep[MaxChars];

    cout<<"������� �������� ������:"<<endl;
    cin.getline(str, MaxChars);
    cout<<"������� ������ ��� ������:"<<endl;
    cin.getline(sub, MaxChars);
    cout<<"������� ����� ������:"<<endl;
    cin.getline(rep, MaxChars);

    char *res = nullptr;
    try {
        res = replace( str, sub, rep);

        cout<<"������ "<<sub<<" <= "<<rep<<endl;
        if(res)
            cout<<res<<endl;
        else
            cout<<"�������� ������ �� �������"<<endl;

    } catch(char *c) {
        cout<<c<<endl;
    }
    delete [] res;

    _CrtDumpMemoryLeaks();

    string sstr=str;
    string ssub=sub;
    string srep=rep;

    try{
        replace(sstr,ssub,srep);
        cout<<endl<<sstr<<endl;
    } catch(char *c) {
        cout<<c<<endl;
    }   

    system("pause");
    return 0;
}
