#include "number.h"

// Случайный ввод обобщенной чисел
bool num_InRnd(number &n) {
    auto k = rand() % 3 + 1;
    switch(k) {
        case 1:
            n.k = number::COMPLEX;
            InRnd(n.c);
            return true;
        case 2:
            n.k = number::POLAR;
            polar_InRnd(n.p);
        case 3:
            n.k = number::FRACTION;
            f_IRnd(n.f);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра чисел
double num_calculation(number &n) {
    switch(n.k) {
        case number::COMPLEX:
            return complex_calculation(n.c);
            break;
        case number::FRACTION:
            return fraction_calculation(n.f);
            break;
        case number::POLAR:
            return polar_calculation(n.p);
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Ввод параметров обобщенной чисел из файла
bool num_In(number& n, ifstream &ifst) {
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            n.k = number::COMPLEX;
            c_In(n.c, ifst);
            return true;
        case 2:
            n.k = number::FRACTION;
            fraction_In(n.f, ifst);
            return true;
        case 3:
            n.k =number::POLAR;
            polar_In(n.p,ifst);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void num_Out(number &n, ofstream &ofst) {
    switch(n.k) {
        case number::COMPLEX:
            c_Out(n.c, ofst);
            break;
        case number::FRACTION:
            fraction_Out(n.f, ofst);
            break;
        case number::POLAR:
            polar_Out(n.p,ofst);
        default:
            ofst << "Incorrect number!" << endl;
    }
}