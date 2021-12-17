#include "number.h"
// Случайный ввод обобщенной чисел
bool number::num_InRnd(number &n) {
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            n.k = number::COMPLEX;
            complex_number::InRnd(n.c);
            return true;
        case 2:
            n.k = number::POLAR;
            polar::polar_InRnd(n.p);
        case 3:
            n.k = number::FRACTION;
            fraction::f_IRnd(n.f);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра чисел
double number::num_calculation(number &n) {
    switch (n.k) {
        case number::COMPLEX:
            return complex_number::complex_calculation(n.c);
            break;
        case number::FRACTION:
            return fraction::fraction_calculation(n.f);
            break;
        case number::POLAR:
            return polar::polar_calculation(n.p);
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Ввод параметров обобщенной чисел из файла
bool number::num_In(number &n, ifstream &ifst) {
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            n.k = number::COMPLEX;
            complex_number::c_In(n.c, ifst);
            return true;
        case 2:
            n.k = number::FRACTION;
            fraction::fraction_In(n.f, ifst);
            return true;
        case 3:
            n.k = number::POLAR;
            polar::polar_In(n.p, ifst);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void number::num_Out(number &n, ofstream &ofst) {
    switch (n.k) {
        case number::COMPLEX:
            complex_number::c_Out(n.c, ofst);
            break;
        case number::FRACTION:
            fraction::fraction_Out(n.f, ofst);
            break;
        case number::POLAR:
            polar::polar_Out(n.p, ofst);
        default:
            ofst << "Incorrect number!" << endl;
    }
}
