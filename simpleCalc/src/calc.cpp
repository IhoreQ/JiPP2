#include <iostream>
#include <cstdlib>
#include "../headers/calc.h"

// Funkcja dodająca dwa podane argumenty
int sumValues(int a, int b) {
    return a + b;
}

// Funkcja odejmująca od argumentu a argument b
int subtractValues(int a, int b) {
    return a - b;
}

// Funkcja obliczająca objetosc graniastoslupa prostego o podstawie trapezu
int countVolume(int a, int b, int h, int H) {
    return (a + b) * h * H * 0.5;
}

// Funkcja wyswietlajaca dokumentacje
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

// Funkcja wypisujaca blad na ekran
void printError() {
    cout << "Blednie podano argumenty funkcji!" << endl;
}