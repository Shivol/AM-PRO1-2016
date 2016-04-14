//
// Лабораторная работа №10. Текстовые файлы
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

     // сохраняем старый буфер вывода
    streambuf *cout_buffer = cout.rdbuf();
    // перенаправляем буфер вывода в файл
    cout.rdbuf(test_out.rdbuf());         
    // теперь весь вывод в std::cout уходит в файл test_out

    print_len(input);

    // завершаем операции с буфером
    cout.flush();
    // восстанавливаем старый буфер вывода
    cout.rdbuf(cout_buffer);
    // закрвываем файл с выводом
    test_out.close();

    // сравним содержимое файла вывода с ожидаемым содержимым файла
    assert(is_equal_text(test_out_name, output));

    // удалим временный файл
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