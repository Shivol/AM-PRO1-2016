//
// Лабораторная работа №10. Текстовые файлы
// test_text.h
//

// Тестирования работы функции
// void print_len(const char *filename)
// Входные параметры:
//     input - имя файла входных данных;
//     output -  имя фала с ожидаемым результатом.
bool test_print_len(const char *input, const char *output);

// Тестирования работы функции
// bool is_equal_file(const char*filename1, const char *filename2)
// Входные параметры:
//     filename1 - имя файла входных данных;
//     filename2 - имя другого файла входных данных.
bool test_is_equal_text(const char *filename1, const char *filename2);


// Полный тест библиотеки
bool test_full_text();