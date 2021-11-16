#include "../include/ComplexNumber.h"
#include <iostream>
#include <cmath>

using namespace std;

ComplexNumber::ComplexNumber(): real(0), imaginary(0) {}

ComplexNumber::ComplexNumber(double real, double imaginary): real(real), imaginary(imaginary) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) const {
    return {real + rhs.real, imaginary + rhs.imaginary};
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& rhs) const {
    return {real - rhs.real, imaginary - rhs.imaginary};
}

double ComplexNumber::operator*(const ComplexNumber& rhs) const {
    return sqrt(pow(real + rhs.real, 2) + pow(imaginary + rhs.imaginary, 2));
}

ComplexNumber ComplexNumber::operator*(const double &number) const {
    return {real * number, imaginary * number};
}

bool ComplexNumber::operator==(const ComplexNumber &rhs) const {
    if (real == rhs.real && imaginary == rhs.imaginary)
        return true;
    else
        return false;
}

ComplexNumber operator*(const double& n, const ComplexNumber& rhs) {
    return {rhs.real * n, rhs.imaginary * n};
}

ostream& operator<<(ostream& lhs, const ComplexNumber& rhs) {
    lhs << "(" << rhs.real << "," << rhs.imaginary << ")";
    return lhs;
}