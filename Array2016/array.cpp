//
// ������������ ������� �3. �������, ��������� ��������.
// array.cpp
//
#include <assert.h>
#include <iostream>
#include "array.h"

using namespace std;

void read(int *a, int &n)
{
    cout<<"������� N<"<<max_N<<endl;
    do {
        cin>>n;
    } while( n<1 || n>=max_N);

    cout<<"������� "<<n<<" ��������"<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];
}

void print(const int *a, int n)
{
    assert(n>0 && n<max_N);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int product_positive_after_zero(const int *a, int n)
{
    assert(n>0 && n<max_N);

    int i = 0;
    while ( a[i] && i<n ) 
        i++;
    if ( i==n ) 
        throw "� ������� ��� ����";

    int prod = 1;
    bool pos = 0;  //���� - ������� �������������� ��������

    while ( i<n ) {
        if( a[i]>0 ) {
            prod *= a[i];
            pos = 1;
        }
        i++;
    }

    if( pos ) return prod;
    return 0;
}