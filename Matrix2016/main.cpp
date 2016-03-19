//
// Лабораторная раюота №7. Двумерные массивы
//
//

#include <iostream>
#include "crtdynmem.h"
#include "test_matrix.h"

using namespace std;

int main()
{
    test_is_equal("test_matrix.txt");
    _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}