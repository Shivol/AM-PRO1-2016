//
// Лабораторная работа №12. Структуры в динамической памяти
// structs_dynamic.cpp
//
#include <cassert>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "structs.h"
#include "structs_dynamic.h"


using namespace std;

student get_student(const std::string &s)
{
    student stud;
    istringstream sin(s);

    sin.getline(stud.fullname, student::name_size, '\t');

    sin >> stud.course >> stud.group;

    for (size_t i = 0; i < student::assign_count; ++i) {
        sin >> stud.credits[i];
    }

    if (strlen(stud.fullname) == 0 || !sin.eof())
        throw "Неверный формат входной строки";

    return stud;
}

void binary_from_text(const char *filename)
{
    assert(filename != nullptr);
    ifstream fin(filename);
    if (!fin.is_open())
        throw "Невозможно открыть файл";

    string dataname = filename;
    size_t dot = dataname.find_last_of('.');
    dataname.replace(dot, dataname.length() - dot, ".dat");

    ofstream fout(dataname, ios::binary);
    if (!fout.is_open())
        throw "Невозможно открыть файл";

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