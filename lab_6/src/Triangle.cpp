//
// Created by IhoreQ on 16/11/2021.
//

#include <iostream>
#include "../include/Triangle.h"

using namespace std;

Triangle::Triangle(Node a, Node b, Node c, string name) {
    node[0] = a;
    node[1] = b;
    node[2] = c;
    this->name = name;
}

void Triangle::display() {
    cout << "Trojkat: " << name << endl;
    node[0].display();
    node[1].display();
    node[2].display();
}

ostream& operator<<(ostream& lhs, Triangle& triangle) {
    lhs << "Trojkat: " << triangle.name << endl;
    lhs << triangle.node[0] << endl;
    lhs << triangle.node[1] << endl;
    lhs << triangle.node[2];
    return lhs;
}

double Triangle::distance(int firstPointIndex, int secondPointIndex) {
    return pointsDistance(node[firstPointIndex], node[secondPointIndex]);
}

/* Nie można użyć
void showTriangleData(Triangle triangle) {
    triangle.display();
}
*/
void showTriangleData(Triangle& triangle) {
    triangle.display();
}
void showTriangleData(Triangle* triangle) {
    (*triangle).display();
}