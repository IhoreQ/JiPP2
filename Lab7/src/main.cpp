#include <iostream>
#include "../include/Figura.h"

using namespace std;

int main() {

    Figura* Kolo = new Circle(4);
    Figura* Prostokat = new Rectangle(2, 10);

    cout << "Pole kola: " << Kolo->getArea() << endl << "Obwod kola: " << Kolo->getCircumference() << endl;
    cout << "Pole prostokata: " << Prostokat->getArea() << endl << "Obwod prostokata: " << Prostokat->getCircumference() << endl;

    return 0;
}
