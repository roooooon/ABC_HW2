//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include "container.h"
void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    unsigned int start_time = clock(); // начальное время
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start"<< endl;
    container con{};
    container::Init(con);

    ////cout << "argv[1] = " << argv[1] << "\n";
    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        container::con_In(con, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            cout << "incorrect number of numbers = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        container::con_InRnd(con, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    container::con_Out(con, ofst1);

    // The 2nd part of task
    ofstream ofst2(argv[4]);
    ofst2 << "Binary insertion by quotient:" << "\n";
    container::Binaryinsertion(reinterpret_cast<int *>(con.cont), con.len);
    container::con_Out(con, ofst2);
    container::con_Clear(con);
    cout << "Stop" << endl;
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "Time: " << search_time << " milliseconds" << endl;
    ofst1 << "Time: " << search_time << " milliseconds" << endl;
    ofst2 << "Time: " << search_time << " milliseconds" << endl;
    return 0;

}
