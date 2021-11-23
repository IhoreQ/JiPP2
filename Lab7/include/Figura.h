//
// Created by IhoreQ on 23/11/2021.
//

#ifndef LAB7_FIGURA_H
#define LAB7_FIGURA_H

#include <iostream>

using namespace std;

class Figura {
protected:
    string nazwa;
    string kolor;
public:
    virtual double getArea() = 0;
    virtual double getCircumference() = 0;
};

class Circle : public Figura {
public:
    Circle(double radius);
    double getArea() override;
    double getCircumference() override;

private:
    double radius;
};

class Rectangle : public Figura {
public:
    Rectangle(double a, double b);
    double getArea() override;
    double getCircumference() override;

private:
    double a, b;
};


#endif //LAB7_FIGURA_H
