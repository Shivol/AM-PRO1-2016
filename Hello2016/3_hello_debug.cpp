#include <iostream>

using namespace std;

/*
	�������������� �������� ��� ������� ������������� ��������� �������: 
	1 � ��������, 2 � ���������, 3 � ���������, 4 � �������. 
	��� ����� �������� N (����� ����� � ��������� 1�4) � ������������ ����� A � B (B �� ����� 0). 
	��������� ��� ������� ��������� �������� � ������� ���������.
*/

int _3_main()
{
	setlocale(LC_ALL, "Rus");
	cout<<"������� ��� ��������:"<<endl
		<<"1 � ��������,"<<endl
		<<"2 � ���������,"<<endl
		<<"3 � ���������,"<<endl
		<<"4 � �������."<<endl;
	int oper;
	cin >> oper;


	int x, y;
	cout<<"������� ��� ����� �����"<<endl;
	cin >> x >> y;

	double result;

	switch (oper)
	{
	case 1: result=x+y;
	case 2: result=x-y;
	case 3: result=x*y;
	case 4: result=x/y;
	default:
		cout<<"�������� ��������"<<endl;		
	}

	if (oper >= 1 && oper <= 4)
		cout<<"���������: "<<result<<endl;

	system ("pause");
	return 0;
}