#include <iostream>
#include "../include/pojazd.h"

using namespace std;

string Pojazd::najnowszaWersjaOprogramowania = "v1.5";

int main() {

    Pojazd Pojazd1("K0 VIPER", 4, "Arona", "Seat");
    Pojazd1.updateInfo(2, "Igor Bobek");
    Pojazd1.wypiszInformacje();

    cout << endl << "Tworzenie kopii pojazdu1..." << endl;
    Pojazd Pojazd1Kopia(Pojazd1);
    Pojazd1Kopia.wypiszInformacje();

    cout << '\n';
    Pojazd1.wypiszWersjeOprogramowania();

    cout << "Akutalizuje wersje oprogramowania..." << endl;
    Pojazd1.zamienWersje();
    Pojazd1.wypiszWersjeOprogramowania();

    Pojazd1.opublikujNoweOprogramowanie("v1.7");
    Pojazd1.zamienWersje();
    Pojazd1.wypiszWersjeOprogramowania();

    return 0;
}
