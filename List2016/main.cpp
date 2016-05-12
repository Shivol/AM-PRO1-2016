//
// ������������ ������ �13. ������������ ��������� ������. ������
// main.cpp
//


#include <iostream>
#include "crtdynmem.h"
#include "tlist.h"
#include "test_tlist.h"

using namespace std;

int main()
{
   setlocale(LC_ALL, "Russian");
    test_tlist_full();

    size_t n;
    cout << "������� ���������� ��������� ������" << endl;
    cin >> n;
    cout << "������� �������� ������" << endl;
    tlist * list = get_list(n);

    tlist *p = find(list, 0);
    int cnt = 0;
    while (p) {  // p != nullptr
        cnt++;
        p = find(p->next, 0);
    }

    cout << "���������� ������� ���������: " << cnt << endl;
    delete_list(list);

    _CrtDumpMemoryLeaks();
    
    system("pause");
    return 0;
}