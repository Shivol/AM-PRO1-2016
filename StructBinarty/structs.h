//
// Лабораторная №11. Структуры. Двоичнвые файлы.
// structs.h
//

#include <cassert>
#include <fstream>

struct point 
{
    double x, y;    
};

struct date
{
    
    uint8_t day, month;
    uint16_t year;
};

struct person
{
    char fullName[128];
    date birthday;
    char gender;
};

template <typename T>
T read_binary( std::ifstream &fin)
{
    T t;
    fin.read(reinterpret_cast<char*> (&t), sizeof(t));
    return t;
}

template <typename T>
void write_binary( std::ofstream &fout, T &t)
{
    fout.write(reinterpret_cast<char*> (&t), sizeof(t));
}

// Шаблонная функция подсчёта количества заданных элементов в файле.
template <typename T>
size_t number_of( const char *filename)
{
    assert(filename);
    
    std::ifstream fin(filename);
    if (!fin.is_open())
        throw "Невозможно открыть файл!";

    size_t count = 0;
    while (!fin.eof()) {
        // считать очередной элемент из файла
        T t = read_binary<T>(fin);
        if (fin)   // если чтение прошло успешно
            count++;
    }

    fin.close();
    return count;
}

