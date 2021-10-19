#include <iostream>
#include "../include/zadania.h"

using namespace std;

int main() {

    // 1. Przeciążenia funkcji
    cout << "Pole kwadratu: " << pole(2, 3) << endl;
    cout << "Pole kwadratu: " << pole(3.0, 4.6) << endl;
    cout << "Pole trapezu: " << pole(2, 3, 4) << endl;
    cout << "Pole trapezu: " << pole(3.2, 3.7, 10.4) << endl;

    // 2. Losowanie liczb

    /*
    int a, b;
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << "Losowa liczba z przedzialu <a:b> to: " << losuj(a, b) << endl;
    */
    // 3,4. Najwieksza wartosc tablicy i odwracanie jej

    int rozmiarTablicy;
    int start, end;
    srand((unsigned)(time(NULL)));

    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiarTablicy;

    int* randomTab = new int[rozmiarTablicy];

    for (int i = 0; i < rozmiarTablicy; ++i) {
        randomTab[i] = losuj(1, 100);
    }

    cout << "Najwiekszy element z tablicy: " << maxTablica(randomTab, rozmiarTablicy) << endl;

    cout << endl << "Tablica przed odwroceniem kolejnosci: ";

    for (int i = 0; i < rozmiarTablicy; ++i) {
        cout << randomTab[i] << " ";
    }
    cout << endl << "Tablica po odwroceniu kolejnosci: ";

    odwrocKolejnoscTablicy(randomTab, rozmiarTablicy);

    for (int i = 0; i < rozmiarTablicy; ++i) {
        cout << randomTab[i] << " ";
    }

    cout << endl;

    delete [] randomTab;

    return 0;
}


