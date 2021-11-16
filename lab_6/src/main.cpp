#include <iostream>
#include "../include/Node.h"
#include "../include/vector.h"
#include "../include/ComplexNumber.h"
#include "../include/Triangle.h"

using namespace std;

int main() {

    // Punkt
    Node Punkt1;
    Node Punkt2(3,4);
    cout << "Odleglosc miedzy punktami jest rowna: " << pointsDistance(Punkt1, Punkt2) << endl;

    // Wektory
    Vector Wektor1;
    Vector Wektor2(3, 4);
    Vector Wektor3(10, 6);

    cout << "Wektor1 = " << Wektor1 << endl;
    cout << "Wektor2 = " << Wektor2 << endl;
    cout << "Wektor3 = " << Wektor3 << endl;

    cout << "Dlugosc wektora 2: " << Wektor2.length() << endl;
    cout << "Wektor3:" << endl;
    Wektor3.display();

    cout << "Wektor1 + Wektor2 = " << Wektor1 + Wektor2 << endl;
    cout << "Wektor1 - Wektor2 = " << Wektor1 - Wektor2 << endl;
    cout << "Wektor2 * Wektor3 = " << Wektor2 * Wektor3 << endl;
    cout << "Wektor3 * 5 = " << Wektor3 * 5 << endl;
    cout << "5 * Wektor3 = " << 5 * Wektor3 << endl;
    cout << "Wektor przeciwny do Wektora2: " << !Wektor2 << endl;
    cout << "Wektor1 = Wektor2 ? : " << (Wektor1 == Wektor2 ? "Tak":"Nie") << endl;
    cout << "----------------------" << endl;
    // Liczby zespolone

    ComplexNumber A(2, 4);
    ComplexNumber B(8, 9);

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "3 * A = " << 3 * A << endl;
    cout << "A = B? : " << (A == B ? "Tak":"Nie") << endl;

    cout << "----------------------" << endl;
    // Triangle

    Node K, L(2,4), M(2, -4);
    Triangle KLM(K, L, M, "KLM");

    KLM.display();
    cout << KLM << endl;

    cout << "Dystans miedzy 1. a 2. wierzcholkiem = " << KLM.distance(0, 1) << endl;

    showTriangleData(KLM);
    showTriangleData(&KLM);

    return 0;
}
