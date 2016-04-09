//
// Лабораторная работа №9. Обработка строк
//
#pragma once

// Тест для 
// char * replace (const char *source, const char *from, const char* to);
// Проверяет 
//    обычную замену, 
//    повторяющиеся символы 
//    корректную работу при отсутствующей подстроке
bool test_replaceCharPtr();

// Тест для 
// void replace ( string& source, const string &from, const string &to);
// Проверяет 
//    обычную замену, 
//    повторяющиеся символы 
//    корректную работу при отсутствующей подстроке
bool test_replaceString();

bool test_rstring_full();
