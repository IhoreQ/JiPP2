#include <iostream>
#include "funkcjaKwadratowa.h"

using namespace std;

double FunkcjaKwadratowa::getA() {
    return a;
}

double FunkcjaKwadratowa::getB() {
    return b;
}

double FunkcjaKwadratowa::getC() {
    return c;
}

void FunkcjaKwadratowa::setA(double a) {
    this->a = a;
}

void FunkcjaKwadratowa::setB(double b) {
    this->b = b;
}

void FunkcjaKwadratowa::setC(double c) {
    this->c = c;
}

void FunkcjaKwadratowa::wypiszFunkcje() {
    cout << a << "x^2 + " << b << "x + " << c << endl;
}