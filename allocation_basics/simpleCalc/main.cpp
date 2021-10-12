#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int sumValues(int a, int b) {
    return a + b;
}

int subtractValues(int a, int b) {
    return a - b;
}

int countVolume(int a, int b, int h, int H) {
    return (a + b) * h * H * 0.5;
}

void showDocumentation() {

    cout << "Simple calculator" << endl;
    cout << "simpleCalc [nazwa dzialania]" << endl << endl;

    cout << "Dzialania:" << endl;
    cout << "add [a] [b]" << endl << "   Dodawanie dwoch liczb ([a] i [b]) calkowitych." << endl;
    cout << "subtract [a] [b]" << endl << "   Odejmowanie dwoch liczb ([a] i [b]) calkowitych." << endl;
    cout << "volume [a] [b] [h] [H]" << endl << "   Obliczanie objetosci graniastoslupa prostego o podstawie trapezu, gdzie:" << endl;
    cout << "   [a] - dluzsza podstawa, [b] - krotsza podstawa, [h] - wysokosc trapezu, [H] - wysokosc graniastoslupa" << endl;
    cout << "help" << endl << "   Wyswietlenie dokumentacji." << endl;

}

void printError() {
    cout << "Blednie podano argumenty funkcji!" << endl;
}

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
