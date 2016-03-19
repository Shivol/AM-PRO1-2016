//
// Лабораторная раббота №3. Массивы, обработка массивов.
//
// Вычислить произведение положительных элементов массива, 
// следующих после первого нулевого элемента. 
// Если по какой-либо причине вычислить произведение не удается, 
// выдать сообщение об этом.

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
    cout<<"Введите массив целых чисел, содержащий ноль"<<endl;

    read(a,n);
    print(a,n);

    try {
        cout<< "Произведение элементов после первого ноля = "
            << product_positive_after_zero( a, n ) << endl;
    } catch ( char *c) {
        cout<<c<<endl;
    }

    system("pause");
    return 0;
}
