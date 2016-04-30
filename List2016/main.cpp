//
// ������������ ������ �13. ������������ ��������� ������. ������
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
    cout << "������� ���������� ��������� ������" << endl;
    cin >> n;
    cout << "������� �������� ������" << endl;
    list mylist = get_list(n);
    
    tlist *p = find(mylist, 0);
    int cnt = 0;
    while (p != nullptr) {
        cnt++;
        p = find(p->next, 0);
    }

    cout << "���������� ������� ���������: " << cnt << endl;
    
    delete_list(mylist);

    _CrtDumpMemoryLeaks();
    
    system("pause");
    return 0;
}