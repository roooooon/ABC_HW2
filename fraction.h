#ifndef UNTITLED6_FRACTION_H
#define UNTITLED6_FRACTION_H
#include "rnd.h"
#include <fstream>
using namespace std;

class fraction {
public:
    int numerator, denominator;
    //------------------------------------------------------------------------------
// Вычисление значения дроби
    static double fraction_calculation (fraction &f);

//------------------------------------------------------------------------------
// Случайный ввод параметров дроби
    static void f_IRnd(fraction &f);

//------------------------------------------------------------------------------
// Ввод параметров дроби из файла
    static void fraction_In(fraction &f, ifstream &ifst);

//------------------------------------------------------------------------------
// Вывод параметров дроби в форматируемый поток
    static void fraction_Out(fraction &f, ofstream &ofst);
};

#endif //UNTITLED6_FRACTION_H
