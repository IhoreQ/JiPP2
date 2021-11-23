#include <iostream>
#include <cmath>
#include "../include/Figura.h"

using namespace std;

Circle::Circle(double radius): radius(radius) {}

double Circle::getArea() {
    return M_PI * pow(radius, 2);
}

double Circle::getCircumference() {
    return M_PI * 2 * radius;
}

Rectangle::Rectangle(double a, double b): a(a), b(b) {}

double Rectangle::getArea() {
    return a * b;
}

double Rectangle::getCircumference() {
    return 2 * a + 2 * b;
}