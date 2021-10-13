#include <iostream>
#include <cstdlib>
#include <cstring>
#include "../headers/calc.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc > 1) {
        if (strcmp(argv[1], "add") == 0) {
            if (argc == 4)
                cout << "Wynik: " << sumValues(atoi(argv[2]), atoi(argv[3])) << endl;
            else
                printError();
        }
        else if (strcmp(argv[1], "subtract") == 0) {
            if (argc == 4)
                cout << "Wynik: " << subtractValues(atoi(argv[2]), atoi(argv[3])) << endl;
            else
                printError();
        }
        else if (strcmp(argv[1], "volume") == 0) {
            if (argc == 6)
                cout << "Objetosc graniastoslupa: " << countVolume(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]) ) << endl;
            else
                printError();
        }
        else if (strcmp(argv[1], "help") == 0) {
            if (argc == 2)
                showDocumentation();
            else printError();
        }
    }
    else {
        cout << "Poprawne uzycie programu simpleCalc:" << endl << "   simpleCalc [nazwa dzialania]" << endl;
    }

    return 0;
}
