#include <iostream>
#include "kula.h"
#include <cmath>

double Kula::getR() {
    return r;
}
void Kula::setR(double r) {
    this->r = r;
}

double Kula::liczObjetosc() {
    return M_PI * pow(r, 3) * 4/3;
}