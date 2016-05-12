//
// ������������ ������ �15. ���������� ������
// llist.h
//
#pragma once
#include "tlist.h"

// ���� ����������� ������:
//     llist::datatype - ��� ������ ������;
//     data - �������� � ���� ������;
//     prev - ��������� �� ���������� �������;
//     next - ��������� �� ��������� �������.
struct llist
{
    typedef int datatype;
    datatype data;
    llist *prev;
    llist *next;
};

// ������� �������� ����������� ������ �� ������ ������������.
// ������� ���������:
//     source - ��������� �� ������ ��������� ������.
// �������� ��������:
//     end - ��������� �� ����� ������.
// ���������� ��������� �� ������ ������� ������ ������.
llist *get_list(const tlist *source, llist *&end);

// ��������� ������� �������� ��������� ������.
// ������� ���������:
//     begin - ��������� �� ������ ������.
// �������� �������� ��������� begin ����� nullptr.
template <typename List>
void delete_list(List &begin)
{
    while (begin != nullptr) {
        List t = begin;
        begin = begin->next;
        delete t;
    }
}

// ��������� ������� ������ ��������� ������ �� �������.
// ������� ���������:
//     begin - ��������� �� ������ ������.
template <typename List>
void print_list(const List begin) 
{
    while (begin != nullptr) {
        cout << begin->data << ' ';
        begin = begin->next;
    }
    cout << endl;
}

// ��������� ������� ������ �������� � �������� ������.
// ������� ���������:
//     begin - ��������� �� ������ ������;
//     x - ������� ��������.
// ���������� ��������� �� ������ ������� � �������� ��������� ���
// nullptr, ���� �������� � ����� �������� � ������ ���.
template <typename List, typename ListData>
List find(const List begin, ListData x)
{
    List t = const_cast<List>(begin);
    
    while (t != nullptr) {
        if (t->data == x)
            break;
        t = t->next;
    }
    return t;
}