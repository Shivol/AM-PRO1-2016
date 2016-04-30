//
// Лабораторная работа №13. Динамические структуры данных. Списки
// main.cpp
//

#include "crtdynmem.h"
#include <iostream>
#include "tlist.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    size_t n = 0;
    cout << "Введите количество элементов списка" << endl;
    cin >> n;
    cout << "Введите элементы списка" << endl;
    list mylist = get_list(n);
    
    tlist *p = find(mylist, 0);
    int cnt = 0;
    while (p != nullptr) {
        cnt++;
        p = find(p->next, 0);
    }

    cout << "Количество нулевых элементов: " << cnt << endl;
    
    delete_list(mylist);

    _CrtDumpMemoryLeaks();
    
    system("pause");
    return 0;
}