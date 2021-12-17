#ifndef UNTITLED6_CONTAINER_H
#define UNTITLED6_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "number.h"

class container {
public:
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    number cont[max_len];
    //------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
    static void con_InRnd(container &con, int size);

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
    static void con_Out(container &con, ofstream &ofst);

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
    static void con_In(container &con, ifstream &ifst);

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
    static void con_Clear(container &con);

//------------------------------------------------------------------------------
// Инициализация контейнера
    static void Init(container &c);


    static int binarySearch(int *mas, int size , int value, int start, int end);

    static void Binaryinsertion(int* mas, int size);
};

#endif //UNTITLED6_CONTAINER_H
