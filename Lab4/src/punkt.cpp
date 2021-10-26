#include <iostream>
#include "punkt.h"
#include <cmath>

using namespace std;

Punkt::Punkt(int xx, int yy):x(xx),y(yy){};

double Punkt::odlegloscMiedzyPunktami(Punkt innyPunkt) {
    return sqrt(pow((innyPunkt.x - x), 2) + pow((innyPunkt.y - y), 2));
}