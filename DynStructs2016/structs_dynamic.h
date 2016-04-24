//
// Лабораторная работа №12. Структуры в динамической памяти
// structs_dynamic.h 
//
#pragma once
#include <cstdint>
#include <iostream>
#include <string>


// Данные о студенте:
//     fullname - ФИО;
//     course - номер курса;
//     group - номер группы;
//     credits - оценки за лабораторные.
struct student
{
    // количество символов имени
    static const size_t name_size = 128;
    // количество лабораторных работ
    static const size_t assign_count = 10;

    char fullname[name_size];
    uint16_t course, group;
    uint16_t credits[assign_count];
};


// Вычисление суммарного балла студента.
// Входные данные:
//     stud - ссылка на данные студента.
// Возвращает сумммарный балл студента.
uint32_t credits_sum(const student &stud);


// Чтение данных студента из строки.
// Входные данные:
//     s - строка содержащая данные студента,
//     поля разделяются символами табуляции.
// Возвраает заполненную структуру.
// В случае некорректной строки, выбрасывает исключение char*
student get_student(const std::string &s);

// Вывод данных студента в cout.
// Входные данные:
//     stud - ссылка на данные студента.
void print_student(const student &stud);

// Чтение данных из текстового файла и запись в двоичный файл типа student.
// Входные параметры:
//     filename - имя файла данных.
// В результате создаёт файл с именем filename.dat,
// содержащий данные студентов из входного файла.
// В случае проблем с доступом к файлам, выбрасывает исключение char*
void binary_from_text(const char *filename);