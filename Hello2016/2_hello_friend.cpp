
#include <iostream>

// ���������� ��������� �� ������������ ���� std
using std::cout;
using std::endl;
using std::cin;

// ������ �������:
// using namespace std;

// ��������� �������� � ��������� C++
void cmp_age_to_cpp(int age)
{
	if( age < 30 ) 
		cout << "�� � ������ ��� C++!" << endl;
	else
		if( age == 30 ) 
			cout << "�� � ��������� � C++!" << endl;
		else
			cout << "�� � ������ ��� C++!" << endl;

}

int _2_main ()
{
	// ��������� ��������� ����� �� ���������.
	setlocale(LC_ALL, "");
	// ���������� ��� ����������� ����������� ��������� �� �������.

	char name [20];	

	cout << "��� ��� �����?" << endl;

	cin >> name;

	int age;

	cout << "������� ��� ���?" << endl;

	cin >> age;

	cout << "������������, " << name << "!" << endl;

	cmp_age_to_cpp(age);

	system("pause");

	return 0;
}