//
// ������������ ������ �12. ��������� � ������������ ������
// structs_dynamic.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include "structs.h"
#include "structs_dynamic.h"


using namespace std;

uint32_t credits_sum(const student &stud)
{
    uint32_t sum = 0;
    for (int i = 0; i < student::assign_count; ++i) {
        sum += stud.credits[i];
    }
    return sum;
}

student get_student(const string &s)
{
    student stud;
    // ����� ������ �� ������
    istringstream sin(s);

    // ���������� �� ������� ������� ���������
    sin.getline(stud.fullname, student::name_size, '\t');

    sin >> stud.course >> stud.group;
    
    for (size_t i = 0; i < student::assign_count; ++i) {
        sin >> stud.credits[i];
    }
    // ���� ���� ������ ������
    if (!sin.eof() || strlen(stud.fullname) == 0)
        throw "�������� ������ ������� ������";

    return stud;
}

void binary_from_text(const char *filename)
{
    assert(filename != nullptr);
    ifstream fin(filename);
    if (!fin.is_open())
        throw "���������� ������� ����";
    
    // ������ ��� ������ �����
    string dataname = filename;
    size_t dot = dataname.find_last_of('.');
    dataname.replace(dot, dataname.length() - dot, ".dat");

    ofstream fout(dataname, ios::binary);
    if (!fout.is_open())
        throw "���������� ������� ����";

    while (!fin.eof()) {
        string student_str;
        getline(fin, student_str);

        if (student_str.length() != 0) {
            student stud = get_student(student_str);
            write_binary(fout, stud);
        }
    }

    fin.close();
    fout.close();

}

void print_student(const student &stud)
{

    cout << stud.fullname << '\t';
    cout << stud.course << '.' << stud.group << '\t';
    cout << "[ " << stud.credits[0];
    for (size_t i = 1; i < student::assign_count; ++i) {
        cout << ", " << stud.credits[i];
    }
    cout << " ]" << endl;
}