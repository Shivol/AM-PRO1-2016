//
// ������������ ������ �10. ��������� �����
// text.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

#include "text.h"

using namespace std;

void print_len(const char *filename)
{
    assert(filename);
    ifstream fin(filename);
    if(!fin.is_open())
        throw "Couldn't open file!";

    string line;
    while(!fin.eof())
    {
        getline(fin,line);
        cout << line << " : " << line.length() << endl;
    }
    fin.close();
}

bool is_equal_text(const char *filename1, const char *filename2)
{
    assert(filename1);
    assert(filename2);

    ifstream f1(filename1);
    if(!f1.is_open()){
        string error = "Couldn't open file ";
        error.append(filename1);
        throw error.c_str();
    }

    ifstream f2(filename2);
    if(!f2.is_open()){
        string error = "Couldn't open file ";
        error.append(filename2);
        throw error.c_str();
    }
    
    while (!f1.eof() && !f2.eof())
        if(f1.get() != f2.get())
            return false;

    if(!f1.eof() || !f2.eof())
        return false;
    
    f1.close();
    f2.close();
    return true;
}

bool test_print_len(const char *input, const char *output)
{
    assert(input);
    assert(output);
    
    const char* test_out_name = "test_print_len.tmp";
    ofstream test_out(test_out_name);

     // ��������� ������ ����� ������
    streambuf *cout_buffer = cout.rdbuf();
    // �������������� ����� ������ � ����
    cout.rdbuf(test_out.rdbuf());         
    // ������ ���� ����� � std::cout ������ � ���� test_out

    print_len(input);

    // ��������� �������� � �������
    cout.flush();
    // ��������������� ������ ����� ������
    cout.rdbuf(cout_buffer);
    // ���������� ���� � �������
    test_out.close();

    // ������� ���������� ����� ������ � ��������� ���������� �����
    assert(is_equal_text(test_out_name, output));

    // ������ ��������� ����
    remove(test_out_name);

    return true;
}