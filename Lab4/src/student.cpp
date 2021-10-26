#include <iostream>
#include "student.h"

using namespace std;

void Student::wczytajDane() {
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj numer albumu: ";
    cin >> numerAlbumu;
    cout << "Podaj liczbe pytan: ";
    cin >> liczbaPytan;
    cout << "Podaj ilosc poprawnych odpowiedzi: ";
    cin >> poprawneOdpowiedzi;
}

double Student::procentPoprawnych() {

    double wynik = (double)poprawneOdpowiedzi / (double)liczbaPytan * 100;
    return wynik;
}

string Student::getImie() {
    return imie;
}

string Student::getNazwisko() {
    return nazwisko;
}

int Student::getNumerAlbumu() {
    return numerAlbumu;
}

int Student::getLiczbaPytan() {
    return liczbaPytan;
}

int Student::getPoprawneOdpowiedzi() {
    return poprawneOdpowiedzi;
}

void Student::setImie(string imie) {
    this->imie = imie;
}

void Student::setNazwisko(string nazwisko) {
    this->nazwisko = nazwisko;
}

void Student::setNumerAlbumu(int numerAlbumu) {
    this->numerAlbumu = numerAlbumu;
}

void Student::setLiczbaPytan(int liczbaPytan) {
    this->liczbaPytan = liczbaPytan;
}

void Student::setPoprawneOdpowiedzi(int poprawneOdpowiedzi) {
    this->poprawneOdpowiedzi = poprawneOdpowiedzi;
}