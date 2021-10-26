#include <iostream>
#include "figura.h"

using namespace std;

Figura::Figura(int w) {
    this->ileWierzcholkow = w;
    this->wierzcholek = (Punkt*)malloc(w * sizeof(Punkt));
    cout << "Zainicjowalem ilosc wierzcholkow oraz zaalokowalem pamiec dla tablicy wierzcholkow." << endl;
}

Figura::~Figura() {
    free(this->wierzcholek);
    cout << "Usunalem tablice wierzcholkow." << endl;
}