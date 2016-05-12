//
// Лабораторная работа №15. Двусвязный список
// main.cpp
//
#include <iostream>
#include "llist.h"
//#include "test_llist.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // test_tlist_full();

    size_t n;
    cout << "Введите количество элементов списка" << endl;
    cin >> n;
    cout << "Введите элементы списка" << endl;
    tlist *tmplist = get_list(n);
    llist *end;
    llist * begin = get_list(tmplist, end);

    delete_list(tmplist);

    llist *p = find(begin, 0);
    int cnt = 0;
    while (p) {  // p != nullptr
        cnt++;
        p = find(p->next, 0);
    }

    cout << "Количество нулевых элементов: " << cnt << endl;
    delete_list(begin);

    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}