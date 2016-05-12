//
// Лабораторная работа №15. Двусвязный список
// llist.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "llist.h"

using namespace std;

llist *get_list(const tlist *source, llist *&end)
{
    assert(source != nullptr);
    llist *begin = nullptr;
    end = nullptr;

    while (source != nullptr) {
        llist *node = new llist;
        node->data = static_cast<llist::datatype>(source->data);
        node->next = nullptr;
        node->prev = end;

        if (begin == nullptr)
            begin = node;

        if (end != nullptr)
            end->next = node;
        end = node;

        source = source->next;
    }

    return begin;
}

llist *get_list(const char *filename, llist *&end)
{
    assert(filename != nullptr);
    llist *begin = nullptr;
    end = nullptr;

    ifstream fin(filename);
    if (!fin.is_open())
        throw "Невозможно открыть файл";

    llist::datatype data;
    while (fin >> data) {
        llist *node = new llist;
        node->data = data;
        node->next = nullptr;
        node->prev = end;

        if (begin == nullptr)
            begin = node;

        if (end != nullptr)
            end->next = node;
        end = node;
    }

    fin.close();
    return begin;
}
