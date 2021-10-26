 #include <iostream>
#include <cstring>
#include <cstdlib>
#include "structs.h"

void wyswietlDane(samochod obiekt) {
    cout << obiekt.marka << "\t\t\t" << obiekt.model << "\t\t\t\t" << obiekt.rokProdukcji << "\t\t\t\t" << obiekt.kolor << "\t\t\t" << obiekt.przebieg <<  endl;
}


// Dodałem do argumentów funkcji markę, ponieważ musimy jakoś zliczyć samochody danej marki, a nie podając jej, nie wiadomo o jaką chodzi,
// może równie dobrze chodzić o pierwszą z brzegu
int ileTakichSamychMarek(samochod* obiekty, int ileElementow, string marka) {

    int counter = 0;
    for (int i = 0; i < ileElementow; ++i) {
        if (obiekty[i].marka == marka)
            counter++;
    }

    return counter;
}

 int najstarszySamochod(samochod* obiekty, int ileElementow) {

    int min, minI;

    if (obiekty)
        min = obiekty[0].rokProdukcji;
        minI = 0;

    for (int i = 0; i < ileElementow; ++i) {
        if (obiekty[i].rokProdukcji < min) {
            min = obiekty[i].rokProdukcji;
            minI = i;
        }
    }
    return minI;
}