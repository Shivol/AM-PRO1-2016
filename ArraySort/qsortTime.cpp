
#include <iostream>
// библиотека для работы со временем
#include <ctime>
#include "sort.h"

// Функция быстрой сортировки:
// first - указатель на первый элемент массива,
// last  - указатель на последний элемент массива.
void qsort(int *first, int *last)
{ 
    if( first >= last ) return;

    int *left = first;
    int *right = last;
    int *mid = left + (right-left)-1 /2  ;
    do{
        while( *left < *mid ) left++;
        while( *right > *mid ) right--;

        if( left <= right ){
            swap( left, right );
            left++;
            right--;   
        }
    }
    while ( left <= right );

    qsort( first, right );
    qsort( left, last );

}

// Перегрузка qsort для стандартного вызова:
// a - масиив,
// n - число элементов массива.
void qsort(int *a, int n)
{ 
    qsort(a, a + n-1);
}

double sort_time_in_seconds_for( sort_int sort, int* a, const size_t n)
{

    // начало отсчета времени
    clock_t start = clock();
    
    // код для которого замеряем время
    sort(a, n);
    
    // конец отсчета времени
    clock_t stop = clock();
    
    // количество секунд
    double seconds = double(stop - start) / CLOCKS_PER_SEC ;
    
    return seconds;
//    cout<<"Быстрая сортировка"<<endl;
//    cout<<"Для массива из "<<max_n<<" элементов: "<< seconds<<" сек"<<endl;

}