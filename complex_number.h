#ifndef UNTITLED6_COMPLEX_NUMBER_H
#define UNTITLED6_COMPLEX_NUMBER_H

//------------------------------------------------------------------------------
// complex_number.h - содержит описание комплексного числа и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

class complex_number {
public:
    double real , imaginary ;
    //------------------------------------------------------------------------------
// Ввод параметров комплексного числа из потока
    static void c_In(complex_number &c, ifstream &ifst);

//------------------------------------------------------------------------------
// Случайный ввод параметров комплексного числа
    static void InRnd(complex_number &c);

//------------------------------------------------------------------------------
// Вычисление значения комплексного числа
    static double complex_calculation(complex_number &c);

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
    static void c_Out(complex_number &c, ofstream &ofst);

};
#endif //UNTITLED6_COMPLEX_NUMBER_H
