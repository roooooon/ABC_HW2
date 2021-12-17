#ifndef UNTITLED6_NUMBER_H
#define UNTITLED6_NUMBER_H

//------------------------------------------------------------------------------
// number.h - содержит описание обобщённого числа и его интерфейса
//------------------------------------------------------------------------------

#include <iostream>
#include "rnd.h"
#include "fraction.h"
#include "complex_number.h"
#include "polar.h"

class number {
public:
    // значения ключей для каждого из чисел
    enum key {FRACTION, COMPLEX, POLAR};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        polar p;
        fraction f;
        complex_number c;
    };
    // Случайный ввод обобщенной чисел
    static bool num_InRnd(number &n);

//------------------------------------------------------------------------------
// Вычисление периметра чисел
    static double num_calculation(number &n);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной чисел из файла
    static bool num_In(number& n, ifstream &ifst);

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
    static void num_Out(number &n, ofstream &ofst);

};

#endif //UNTITLED6_NUMBER_H
