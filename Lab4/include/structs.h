#ifndef LAB4_STRUCTS_H
#define LAB4_STRUCTS_H
#include <iostream>

using namespace std;

struct samochod {

    string marka;
    string model;
    int rokProdukcji;
    string kolor;
    int przebieg;
};

void wyswietlDane(samochod obiekt);
int ileTakichSamychMarek(samochod* obiekty, int ileElementow, string marka);
int najstarszySamochod(samochod* obiekty, int ileElementow);

#endif //LAB4_STRUCTS_H
