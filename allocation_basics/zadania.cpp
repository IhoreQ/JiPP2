#include <iostream>
#include <cstdlib>
#include "zadania.h"

using namespace std;

// Funkcja wypisująca 5 razy napis 'JiPP2"
void forJiPP() {

    for (int i = 0; i < 5; ++i)
        cout << "JiPP2" << endl;
}

// Funkcja alokująca pamiec dla tablicy 2D, wpisująca do każdego elementu tabeli losowej liczby, wyświetlająca tabele, a na końcu czyszcząca pamięć
void alokowanieTablicy2D() {

    srand((unsigned)time(NULL));
    int wiersze, kolumny;

    cout << "Podaj ilosc wierszy: ";
    cin >> wiersze;
    cout << "Podaj ilosc kolumn: ";
    cin >> kolumny;

    int** tab = new int* [wiersze];

    for (int i = 0; i < wiersze; ++i) {
        tab[i] = new int [kolumny];
    }

    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            tab[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            cout << tab[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < wiersze; ++i) {
        delete [] tab[i];
        tab[i] = NULL;
    }
    delete [] tab;
    tab = NULL;

}
