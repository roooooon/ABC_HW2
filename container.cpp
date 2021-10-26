#include "container.h"

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void con_InRnd(container &con, int size) {
    while(con.len < size) {
        if(num_InRnd(con.cont[con.len])) {
            con.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void con_Out(container &con, ofstream &ofst) {
    ofst << "Container contains " << con.len << " elements." << endl;
    for(int i = 0; i < con.len; i++) {
        ofst << i << ": ";
        num_Out(con.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void con_In(container &con, ifstream &ifst) {
    while(!ifst.eof()) {
        if(num_In(con.cont[con.len], ifst)) {
            con.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void con_Clear(container &con) {
    con.len = 0;
}

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Сортировка языков программирования по их частному
void Binaryinsertion(number* mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    double mid = num_calculation(mas[size / 2]);

    do {
        //В левой части массива оставляем на месте элементы, которые больше центрального
        while (num_calculation(mas[i]) > mid) {

            i++;
        }
        // В правой части пропускаем элементы, которые меньше центрального
        while (num_calculation(mas[j]) < mid) {
            j--;
        }

        // Меняем элементы местами
        if (i <= j) {
            number &tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        Binaryinsertion(mas, j + 1);
    }
    if (i < size) {
        Binaryinsertion(&mas[i], size - i);
    }

}
