//
// Created by IhoreQ on 16/11/2021.
//

#ifndef LAB_6_TRIANGLE_H
#define LAB_6_TRIANGLE_H

#include "../include/Node.h"
#include <iostream>

using namespace std;

class Triangle {
    friend ostream& operator<<(ostream& lhs, Triangle& triangle);

public:
    Triangle(Node a, Node b, Node c, string name);
    void display();
    double distance(int firstPointIndex, int secondPointIndex);
private:
    Node node[3];
    string name;
};
// Nie można jej użyć, ponieważ kompilator podaje błąd o dwuznaczności danej funkcji
// Obie funkcje maja taka sama nazwe i przyjmują taki sam parametr, pomimo że jest to kopia i referencja
//void showTriangleData(Triangle triangle);

void showTriangleData(Triangle& triangle);
void showTriangleData(Triangle* triangle);

#endif //LAB_6_TRIANGLE_H
