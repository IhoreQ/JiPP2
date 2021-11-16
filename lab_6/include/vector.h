#ifndef LAB_6_VECTOR_H
#define LAB_6_VECTOR_H

#include <iostream>
using namespace std;

class Vector {
    friend ostream& operator<<(ostream& lhs, const Vector& rhs);
    friend Vector operator*(const double &lhs, const Vector &rhs);

    double x, y;
public:
    Vector();
    Vector(double x, double y);
    double length();
    Vector operator+(const Vector& rhs);
    Vector& operator+=(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    Vector operator!();
    double operator*(const Vector& rhs);
    Vector operator*(const int skalar);
    bool operator==(const Vector& rhs);
    void display();
};

#endif //LAB_6_VECTOR_H
