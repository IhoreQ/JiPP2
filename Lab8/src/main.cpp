#include <iostream>
#include "../include/Note.h"

using namespace std;

int main() {

    Note* OpisPiotrka = new TextNote("Piotrek", "");

    cout << OpisPiotrka->getContent() << endl;

    OpisPiotrka->setContent();
    string gwiazdki(20, '*');
    cout << "Tytul notatki: " << OpisPiotrka->getTitle();
    cout << endl << gwiazdki << endl;
    cout << OpisPiotrka->getContent() << endl;


    return 0;
}
