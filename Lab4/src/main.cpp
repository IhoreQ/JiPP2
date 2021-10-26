#include <iostream>
#include "structs.h"
#include "prostopadloscian.h"
#include "kula.h"
#include "funkcjaKwadratowa.h"
#include "student.h"
#include "figura.h"
#include "Last.h"

using namespace std;

int main() {

    // STRUKTURY

    samochod samochod1 = {"Peugeot", "407", 2006, "bialy", 176839};
    samochod samochod2 = {"Hyundai", "Coupe", 2002, "srebrny", 198732};
    samochod samochod3 = {"Fiat", "126p", 1964, "zloty", 301437};
    samochod samochod4 = {"Hyundai", "Getz", 2005, "zielony", 147182};

    cout << "Marka: \t\t\t Model: \t\t\t Rok produkcji: \t\t Kolor:" << "\t\t\t" << "Przebieg:" << endl;
    wyswietlDane(samochod1);
    wyswietlDane(samochod2);
    wyswietlDane(samochod3);
    wyswietlDane(samochod4);


    int ileSamochodzikow = 4;
    samochod samochodziki[] = {{"Peugeot", "407", 2006, "bialy", 176839},
                               {"Hyundai", "Coupe", 2002, "srebrny", 198732},
                               {"Fiat", "126p", 1964, "zloty", 301437},
                               {"Hyundai", "Getz", 2005, "zielony", 147182}};

    int teSameMarki = ileTakichSamychMarek(samochodziki, ileSamochodzikow, "Hyundai");

    cout << "Samochodow o tych samych markach: " << teSameMarki << endl;
    int indeks = najstarszySamochod(samochodziki, ileSamochodzikow);
    cout << "Najstarszy samochod to " << samochodziki[indeks].marka << " " <<  samochodziki[indeks].model << endl;

    // KLASY

    Prostopadloscian figura1;
    figura1.setA(10.35);
    figura1.setB(13.37);
    figura1.setC(8.776);

    cout << "Pole calkowite prostopadloscianu: " << figura1.poleProstopadloscianu() << endl;

    Kula kulka;
    kulka.setR(10);
    cout << "Objetosc kuli: " << kulka.liczObjetosc() << endl;

    FunkcjaKwadratowa funkcja1;
    funkcja1.setA(3);
    funkcja1.setB(2.4);
    funkcja1.setC(9);
    cout << "Funkcja: ";
    funkcja1.wypiszFunkcje();

    Student studenciak;

    studenciak.wczytajDane();

    cout << "Procent poprawnych odpowiedzi studenta: " << studenciak.procentPoprawnych() << " %" << endl;

    Punkt A(3,5), B(-9,8);
    cout << "Odleglosc miedzy punktami A i B wynosi: " << A.odlegloscMiedzyPunktami(B) << endl;

    Figura kwadrat(4);
    kwadrat.wierzcholek[0].x = 2;
    kwadrat.wierzcholek[1].y = 4;

    Last ostatniProgramik;
    ostatniProgramik.pause();


    return 0;
}