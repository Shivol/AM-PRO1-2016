//
// Лабораторная работа №9. Обработка строк
//

// Большинство функций библиотеки cstring являются
// устаревшими и вызывают предупреждения компилятора.
// 
// В целях упрощения кода в рамках лабораторной работы
// отключим эти предупреждения для использования этих функций.
#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cstring>
#include "rstring.h"


char *replace (const char *source, const char *from, const char* to)
{
    assert(source);
    assert(from);    
    assert(to);

    if (*from == 0) 
        throw "Нельзя заменить пустую строку.";

    char *result = nullptr;
    size_t lenFrom = strlen( from );
    size_t lenTo = strlen( to );
    const char *next = strstr( source, from );

    if (next == nullptr) return nullptr;

    result = new char[ (next - source) + lenTo + 1];
    strncpy( result, source, next-source);
    result[next-source] = 0;
    strcat( result, to);
    source = next + lenFrom;

    while(next = strstr( source, from)) {
        char *tmp = new char[ strlen( result) + (next - source) + lenTo + 1];
        strcpy( tmp, result);
        strcat( strncat( tmp, source, next-source), to);
        source = next + lenFrom;
        delete [] result;
        result = tmp;
    }

    char *tmp = new char[ strlen( result) + strlen(source) + 1];
    strcpy( tmp, result);
    strcat( tmp, source);
    delete []result;
    result = tmp;

    return result;
}


void replace ( string& source, const string &from, const string &to)
{
    if (from.length() == 0)
        throw "Нельзя заменить пустую строку.";

    size_t next = source.find( from, 0);
    while( next != string::npos) {
        source.replace( next, from.length(), to);
        next = source.find(from, next + to.length() );
    }
}

#undef _CRT_SECURE_NO_WARNINGS
