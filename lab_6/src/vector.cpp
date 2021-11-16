#include "../include/vector.h"
#include <cmath>
#include <iostream>

using namespace std;

Vector::Vector(): x(0), y(0) {}

Vector::Vector(double x, double y): x(x), y(y) {}

double Vector::length() {
    return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector& rhs) {
    return {x + rhs.x, y + rhs.y};
}

Vector& Vector::operator+=(const Vector& rhs) {
    this->x = this->x + rhs.x;
    this->y = this->y + rhs.y;
    return *this;
}

Vector Vector::operator-(const Vector& rhs) {
    return {x - rhs.x, y - rhs.y};
}

Vector Vector::operator!() {
    return {-x, -y};
}

void Vector::display() {
    cout << "x = " << x << endl << "y = " << y << endl;
}

double Vector::operator*(const Vector& rhs) {
    return (x * rhs.x + y * rhs.y);
}

Vector Vector::operator*(const int skalar) {
    return {x * skalar, y * skalar};
}

bool Vector::operator==(const Vector& rhs) {
    if (x == rhs.x && y == rhs.y)
        return true;
    else
        return false;
}

Vector operator*(const double &lhs, const Vector &rhs) {
    return {rhs.x * lhs, rhs.y * lhs};
}

ostream& operator<<(ostream& lhs, const Vector& rhs) {
    lhs << "[" << rhs.x << "," << rhs.y << "]";
    return lhs;
}