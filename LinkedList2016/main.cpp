//
// ������������ ������ �15. ���������� ������
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
    cout << "������� ���������� ��������� ������" << endl;
    cin >> n;
    cout << "������� �������� ������" << endl;
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

    cout << "���������� ������� ���������: " << cnt << endl;
    delete_list(begin);

    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}