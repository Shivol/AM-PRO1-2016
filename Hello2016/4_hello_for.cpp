// hello_for.cpp
#include <iostream>
using namespace std;

/* 
    ���� ������������������ �� N �����.
    ������� ��� �������� �������� ����� ����������.
*/

int _4_main() {
	
	setlocale(LC_ALL, "");

	int n;
	cout<<"������� ���������� �����"<<endl;
	cin>>n;

	cout<<"������� "<<n<<" ����� � �������"<<endl;

	int x, y=0;
	for ( int i=1; i<n-1; ++i ) 
	{
		cin>>x;
		if (x % 2 > 0)
		{
			if( y>0 ) cout<<y<<endl;
			y = x;
		}
	}	
	system("pause");
	return 0;
}