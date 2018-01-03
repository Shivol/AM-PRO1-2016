#include <iostream>

using namespace std;

/*
	Арифметические действия над числами пронумерованы следующим образом: 
	1 — сложение, 2 — вычитание, 3 — умножение, 4 — деление. 
	Дан номер действия N (целое число в диапазоне 1–4) и вещественные числа A и B (B не равно 0). 
	Выполнить над числами указанное действие и вывести результат.
*/

int _3_main()
{
	setlocale(LC_ALL, "Rus");
	cout<<"Введите код оепрации:"<<endl
		<<"1 — сложение,"<<endl
		<<"2 — вычитание,"<<endl
		<<"3 — умножение,"<<endl
		<<"4 — деление."<<endl;
	int oper;
	cin >> oper;


	int x, y;
	cout<<"Введите два целых числа"<<endl;
	cin >> x >> y;

	double result;

	switch (oper)
	{
	case 1: result=x+y;
	case 2: result=x-y;
	case 3: result=x*y;
	case 4: result=x/y;
	default:
		cout<<"Неверная операция"<<endl;		
	}

	if (oper >= 1 && oper <= 4)
		cout<<"Результат: "<<result<<endl;

	system ("pause");
	return 0;
}