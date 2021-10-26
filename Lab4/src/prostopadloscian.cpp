#include <iostream>
#include <prostopadloscian.h>
using namespace std;

double Prostopadloscian::getA() {
    return a;
}

double Prostopadloscian::getB() {
    return b;
}

double Prostopadloscian::getC() {
    return c;
}

void Prostopadloscian::setA(double a) {
    this->a = a;
}

void Prostopadloscian::setB(double b) {
    this->b = b;
}

void Prostopadloscian::setC(double c) {
    this->c = c;
}

double Prostopadloscian::poleProstopadloscianu() {
    return a * b * 2 + a * c * 2 + b * c * 2;
}