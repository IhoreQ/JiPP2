#include <iostream>
#include <cstring>
#include "../include/pojazd.h"

using namespace std;

Pojazd::Pojazd(string rejestracja, int iloscMiejsc, string nazwa, string marka) {
    this->rejestracja = rejestracja;
    this->nazwa = nazwa;
    this->marka = marka;
    this->iloscMiejsc = iloscMiejsc;
    this->dane = new string[iloscMiejsc];
    this->zainstalowanaWersjaOprogramowania = "v1.0";

    for (int i = 0; i < iloscMiejsc; ++i)
        this->dane[i] = "puste";
}

Pojazd::Pojazd(Pojazd& klasaPojazdu) {
    rejestracja = klasaPojazdu.rejestracja;
    nazwa = klasaPojazdu.nazwa;
    marka = klasaPojazdu.marka;
    iloscMiejsc = klasaPojazdu.iloscMiejsc;
    zainstalowanaWersjaOprogramowania = klasaPojazdu.zainstalowanaWersjaOprogramowania;
    najnowszaWersjaOprogramowania = klasaPojazdu.najnowszaWersjaOprogramowania;
    dane = new string[iloscMiejsc];
    for (int i = 0; i < iloscMiejsc; ++i)
        dane[i] = klasaPojazdu.dane[i];
}

Pojazd::~Pojazd() {
    delete [] dane;
}

void Pojazd::wypiszInformacje() {

    cout << "Marka: " << marka << endl;
    cout << "Nazwa: " << nazwa << endl;
    cout << "Numer rejestracyjny: " << rejestracja << endl;
    cout << "Ilosc miejsc: " << iloscMiejsc << endl;
    cout << "Siedzenia w samochodzie: " << endl;

    for (int i = 0; i < iloscMiejsc; ++i) {
        cout << "Miejsce " << i + 1 << ": " << dane[i] << endl;
    }
}

void Pojazd::updateInfo(int nrMiejsca, string info) {

    if (nrMiejsca < 1 || nrMiejsca > iloscMiejsc) {
        cout << "Podano bledny numer miejsca!" << endl;
    } else {
        dane[nrMiejsca - 1] = info;
    }
}

string Pojazd::getRejestracja() {
    return rejestracja;
}

string Pojazd::getNazwa() {
    return nazwa;
}

string Pojazd::getMarka() {
    return marka;
}

void Pojazd::setNazwa(string nowaNazwa) {
    nazwa = nowaNazwa;
}

void Pojazd::setRejestracja(string nowaRestracja) {
    rejestracja = nowaRestracja;
}

void Pojazd::wypiszWersjeOprogramowania() {
    cout << "Zainstalowana wersja oprogramowania: " << zainstalowanaWersjaOprogramowania << endl;
}

void Pojazd::zamienWersje() {
    zainstalowanaWersjaOprogramowania = najnowszaWersjaOprogramowania;
}

void Pojazd::opublikujNoweOprogramowanie(string nowaWersja) {
    najnowszaWersjaOprogramowania = nowaWersja;
}