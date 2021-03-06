//------------------------------------------------------------------------------
// fraction.c - содержит процедуру ввода параметров
// для уже созданной дроби
//------------------------------------------------------------------------------

#include "fraction.h"
#include <fstream>
using namespace std;
//------------------------------------------------------------------------------
// Вычисление значения дроби
double fraction::fraction_calculation(fraction &f) {
    return (double)f.numerator / (double)f.denominator;
}

//------------------------------------------------------------------------------
// Случайный ввод параметров дроби
void fraction::f_IRnd(fraction &f) {
    f.numerator = Random();
    f.denominator = Random();
}
//------------------------------------------------------------------------------
// Ввод параметров дроби из файла
void fraction::fraction_In(fraction &f, ifstream &ifst) {
    ifst >> f.numerator >> f.denominator;
}
//------------------------------------------------------------------------------
// Вывод параметров дроби в форматируемый поток
void fraction::fraction_Out(fraction &f, ofstream &ofst) {
    ofst << "It is Fraction: numerator = " << f.numerator << ", denominator = " << f.denominator
         << ". the fraction = " << fraction::fraction_calculation(f) << "\n";
}
