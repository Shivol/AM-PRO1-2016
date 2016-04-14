//
// ������������ ������ �10. ��������� �����
// test_text.h
//

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

#include "test_text.h"
#include "text.h"

using namespace std;

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

#ifndef _DEBUG
    cerr << "test print_len : OK" << endl;
#endif /* _DEBUG */
    return true;
}

bool test_is_equal_text(const char *eqfile1, const char *eqfile2, const char *diffile)
{
    assert(eqfile1);
    assert(eqfile2);
    assert(diffile);

    assert(is_equal_text(eqfile1, eqfile1));
    
    assert(is_equal_text(eqfile2, eqfile2));

    assert(is_equal_text(diffile, diffile));

    assert(is_equal_text(eqfile1, eqfile2));

    assert(!is_equal_text(eqfile2, diffile));

    assert(!is_equal_text(eqfile1, diffile));

#ifndef _DEBUG
    cerr << "test is_equal_text : OK" << endl;
#endif /* _DEBUG */
    return true;
}