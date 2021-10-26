
#include "complex_number.h"

//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из потока
void c_In(complex_number &c, ifstream &ifst) {
    ifst >> c.real >> c.imaginary ;
}

//------------------------------------------------------------------------------
// Случайный ввод параметров комплексного числа
void InRnd(complex_number &c){
    c.real = Random();
    c.imaginary = Random();
}

//------------------------------------------------------------------------------
// Вычисление значения комплексного числа
double complex_calculation(complex_number &c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
void c_Out(complex_number &c, ofstream &ofst) {
    ofst << "It is complex number: the real = "
         << c.real << ", the imaginary = " << c.imaginary
         << ". complex calculation = " << complex_calculation(c) << "\n";
}

