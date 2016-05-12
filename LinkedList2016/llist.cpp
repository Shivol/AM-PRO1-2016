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


