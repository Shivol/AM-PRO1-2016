//
// ������������ ������ �10. ��������� �����
// test_text.cpp
//

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

#include "test_text.h"
#include "text.h"

using namespace std;

//
bool test_print_len(const char *input, const char *output)
{
    assert(input);
    assert(output);
    

    // ������ ��������� ����
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

#ifdef _DEBUG
    cerr << "test print_len : OK" << endl;
#endif /* _DEBUG */
    return true;
}

//
bool test_is_equal_text(const char *filename1, const char *filename2)
{
    assert(filename1);
    assert(filename2);

    assert(is_equal_text(filename1, filename1));
    
    assert(is_equal_text(filename2, filename2));

    assert(!is_equal_text(filename2, filename1));

    assert(!is_equal_text(filename1, filename2));

#ifdef _DEBUG
    cerr << "test is_equal_text : OK" << endl;
#endif /* _DEBUG */
    return true;
}

bool test_full_text()
{
    const char *input = "jabberwocky.txt";
    const char *output = "jabberwocky_test.txt";
    return test_is_equal_text(input, output) 
        && test_print_len(input, output);
}