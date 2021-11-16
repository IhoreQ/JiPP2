//
// Created by IhoreQ on 16/11/2021.
//

#ifndef LAB_6_COMPLEXNUMBER_H
#define LAB_6_COMPLEXNUMBER_H

#include <iostream>

using namespace std;

class ComplexNumber {

    friend ComplexNumber operator*(const double& n, const ComplexNumber& rhs);// Mnożenie przez skalar
    friend ostream& operator<<(ostream& lhs, const ComplexNumber& rhs);

public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);

    ComplexNumber operator+(const ComplexNumber& rhs) const; // Dodawanie
    ComplexNumber operator-(const ComplexNumber& rhs) const; // Odejmowanie
    double operator*(const ComplexNumber& rhs) const; // Iloczyn skalarny
    ComplexNumber operator*(const double &number) const; // Mnożenie przez skalar
    bool operator==(const ComplexNumber &rhs) const; // Porównywanie liczb zespolonych

private:
    double real, imaginary;
};

#endif //LAB_6_COMPLEXNUMBER_H
