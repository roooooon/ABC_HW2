

#include "complex_number.h"

//------------------------------------------------------------------------------
// Вычисление значения комплексного числа
double complex_number::complex_calculation(complex_number &c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}
//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
void complex_number::c_Out(complex_number &c, ofstream &ofst) {
    ofst << "It is complex number: the real = "
         << c.real << ", the imaginary = " << c.imaginary
         << ". complex calculation = " << complex_calculation(c) << "\n";
}
//------------------------------------------------------------------------------
// Случайный ввод параметров комплексного числа
void complex_number::InRnd(complex_number &c) {
    c.real = Random();
    c.imaginary = Random();
}
//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из потока
void complex_number::c_In(complex_number &c, ifstream &ifst) {
    ifst >> c.real >> c.imaginary ;
}

