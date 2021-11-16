#ifndef LAB_6_NODE_H
#define LAB_6_NODE_H

#include <iostream>

using namespace std;

class Node {
    friend double pointsDistance(Node a, Node b);
    friend ostream& operator<<(ostream& lhs, Node& rhs);

public:
    Node();
    Node(double x, double y);

    void display();
    void updateValue(double x, double y);
private:
    double x, y;
};

double pointsDistance(Node a, Node b);

#endif //LAB_6_NODE_H
