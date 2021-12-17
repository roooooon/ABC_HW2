#include "container.h"
//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void container::con_InRnd(container &con, int size) {
    while(con.len < size) {
        if(number::num_InRnd(con.cont[con.len])) {
            con.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void container::con_Out(container &con, ofstream &ofst) {
    ofst << "Container contains " << con.len << " elements." << endl;
    for(int i = 0; i < con.len; i++) {
        ofst << i << ": ";
        number::num_Out(con.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void container::con_In(container &con, ifstream &ifst) {
    while(!ifst.eof()) {
        if(number::num_In(con.cont[con.len], ifst)) {
            con.len++;
        }
    }
}
//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void container::con_Clear(container &con) {
    con.len = 0;
}

//------------------------------------------------------------------------------
// Инициализация контейнера
void container::Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Сортировка языков программирования по их частному
int container::binarySearch(int *mas, int size, int value, int start, int end) {
    if (start == end) {
        if (mas[start] < value) {
            return start;
        } else return start + 1;
    }
    if (start > end)
        return start;

    long long mid = (start + end) / 2;
    if (mas[mid] > value) {
        return binarySearch(mas,size, value, mid + 1, end);
    } else if (mas[mid] < value) {
        return binarySearch(mas,size, value, start, mid - 1);
    } else
        return mid;
}

void container::Binaryinsertion(int *mas, int size) {
    for (int i = 1; i < size; ++i) {
        //cout << mas[i];
        //cout <<"\n";
        int j = i - 1;
        int value = mas[i];
        int index = binarySearch(mas, size, value, 0, j);
        while (j >= index) {
            mas[j + 1] = mas[j];
            --j;
        }

    }
}
