//
// Ћабораторна€ работа є9. ќбработка строк
//

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cassert>
#include <iostream>

#include "rstring.h"
#include "test_rstring.h"


bool test_replaceCharPtr()
{
    // проста€ замена
    {
        char *source = "eeny meeny miny moe";
        char *from = "eny";
        char *to = "arly";
        char *result = "early mearly miny moe";
        char *test = replace(source, from, to);

        assert(strcmp(result, test) == 0);

        delete test;
    }
    // замена повтор€ющихс€ символов
    {
        char *source = "xxXxxxXxxxxxX";
        char *from = "xx";
        char *to = "0";
        char *result = "0X0xX00xX";
        char *test = replace(source, from, to);

        assert(strcmp(result, test) == 0);

        delete test;
    }
    // отсутсвие подстроки
    {
        char *source = "eeny meeny miny moe";
        char *from = "xx";
        char *to = "0";
        char *result = nullptr;
        char *test = replace(source, from, to);

        assert(result == test);

        delete test;
    }
    // замена пустой строки
    {
        char *source = "eeny meeny miny moe";
        char *from = "";
        char *to = "0";
        try {
            replace(source, from, to);
            assert(0);
        }
        catch (...) {
            assert(1);
        }
    }

    return true;
}

bool test_replaceString()
{
    // обычна€ замена
    {
        string source = "eeny meeny miny moe";
        string from = "eny";
        string to = "arly";
        string result = "early mearly miny moe";

        replace(source, from, to);
        assert(result == source);
    }
    // замена повтор€ющихс€ символов
    {
        string source = "xxXxxxXxxxxxX";
        string from = "xx";
        string to = "0";
        string result = "0X0xX00xX";

        replace(source, from, to);
        assert(result == source);
    }
    // отсутсвующа€ подстрока
    {
        string source = "eeny meeny miny moe";
        string from = "xx";
        string to = "0";
        string result = "eeny meeny miny moe";

        replace(source, from, to);
        assert(result == source);
    }
    // замена пустой строки
    {
        string source = "eeny meeny miny moe";
        string from = "";
        string to = "0";

        try {
            replace(source, from, to);
            assert(1);
        }
        catch (...) {
            assert(1);
        }

    }

    return true;
}

bool test_rstring_full()
{
    std::cout << "test replace char * :" << (test_replaceCharPtr() ? "ok" : "fail") << std::endl;
    std::cout << "test replace string :" << (test_replaceString() ? "ok" : "fail") << std::endl;
    return true;
}

#undef _CRT_SECURE_NO_WARNINGS
