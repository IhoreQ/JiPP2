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


    int a, b;
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << "Losowa liczba z przedzialu <a:b> to: " << losuj(a, b) << endl;


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

    // 5. Srednia wskaznikow

    double liczba1, liczba2;
    double wynik;

    cout << "Podaj liczbe1: ";
    cin >> liczba1;
    cout << "Podaj liczbe2: ";
    cin >> liczba2;

    double* wsk_liczba1 = &liczba1;
    double* wsk_liczba2 = &liczba2;
    double* wsk_wynik = &wynik;

    liczSrednia(wsk_liczba1, wsk_liczba2, wsk_wynik);

    cout << "Srednia tych liczb: " << wynik << endl;

    // 6. Wypisanie elementow wiekszych od 50 na wskaznikach

    cout << "Elementy tablicy wieksze od 50: ";
    wypiszElementy(randomTab, rozmiarTablicy);

    delete [] randomTab;

    // 7. Sortowanie zmiennych

    int q, w, e;
    cout << "Podaj liczbe 1: ";
    cin >> q;
    cout << "Podaj liczbe 2: ";
    cin >> w;
    cout << "Podaj liczbe 3: ";
    cin >> e;

    sortujElementy(&q, &w, &e);

    cout << "Posortowane elementy: " << q << " " << w << " " << e << endl;

    // 8. Przypisanie do wskaznika na zmienna zmiennej

    int r;
    int* pR = &r;

    wpisanieWskaznikaWZmienna(5, pR);
    cout << "Wartosc w: " << r << endl;



    // 9. Obsluga bledow przy dzieleniu liczb


    int dzielna, dzielnik = 0;

    cout << "Podaj liczbe 1: ";
    cin >> dzielna;

    while (dzielnik == 0) {
        try {
            cout << "Podaj liczbe 2: ";
            cin >> dzielnik;
            if (dzielnik == 0)
                throw "Nie mozna dzielic przez 0!";
        }
        catch(const char* message) {
            cout << message << endl;
        }
    }

    try {
        if ((dzielna % dzielnik) != 0)
            throw "Nie mozna podzielic tych liczb!";
        cout << "Wynik dzielenia: " << dzielna / dzielnik << endl;
    }
    catch(const char* message) {
        cout << message << endl;
    }

    // 10. Konwersja ciągu znaków

    konwertujCiagZnakow("Kamil#Zdun");

    return 0;
}


