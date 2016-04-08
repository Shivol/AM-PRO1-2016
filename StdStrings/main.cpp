//
// Лабораторная работа №9. Обработка строк
//

#include <iostream>
#include <crtdbg.h>
#include <windows.h>  // для использования кириллицы в консоли

#include "rstring.h"
#include "test_rstring.h"

using namespace std;

int main()
{
    // Для ВВОДА кириллицы в Windows 
    // необходимо совершить несколько 
    // дополнительных манипуляций

    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    test_rstring_full();

    const int MaxChars = 100;
    char str[MaxChars];
    char sub[MaxChars];
    char rep[MaxChars];

    cout<<"Введите исходную строку:"<<endl;
    cin.getline(str, MaxChars);
    cout<<"Введите строку для замены:"<<endl;
    cin.getline(sub, MaxChars);
    cout<<"Введите новую строку:"<<endl;
    cin.getline(rep, MaxChars);

    char *res = nullptr;
    try {
        res = replace( str, sub, rep);

        cout<<"Замена "<<sub<<" <= "<<rep<<endl;
        if(res)
            cout<<res<<endl;
        else
            cout<<"Исходная строка не найдена"<<endl;

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
