#include <iostream>
#include "zadania.h"
#include <cstring>

using namespace std;

// 1.
double pole(double a, double b) {
    return a * b;
}

int pole(int a, int b) {
    return a * b;
}

double pole(double a, double b, double c) {
    return 0.5 * (a+b) * c;
}

int pole(int a, int b, int c) {
    return 0.5 * (a+b) * c;
}

// 2.
int losuj(int a, int b) {
    b -= a;
    return (rand() % b) + a;
}

// 3.

int maxTablica(int* tab, int tabSize) {

    int max = 0;
    for (int i = 0; i < tabSize; ++i) {
        if (tab[i] > max)
            max = tab[i];
    }

    return max;
}

// 4.

void odwrocKolejnoscTablicy(int* tab, int tabSize) {

    int temp;

    for (int i = 0; i < tabSize / 2; i++) {
        temp = tab[i];
        tab[i] = tab [tabSize - i - 1];
        tab[tabSize - i - 1] = temp;
    }

}

// 5.

void liczSrednia(double* a, double* b, double* wynik) {

    *wynik = (*a + *b) / 2;
}

// 6.

void wypiszElementy(int* tab, int tabSize) {

    for (int* p = tab; p < tab + tabSize; ++p) {
        if (*p > 50)
            cout << *p << " ";
    }
    cout << endl;
}

// 7.

void zamiana(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortujElementy(int* a, int* b, int* c) {

    if (*a > *b)
        zamiana(a,b);
    if (*a > *c)
        zamiana(a,c);
    if(*b > *c)
        zamiana(b,c);
}

// 8.

void wpisanieWskaznikaWZmienna(int x, int* w) {
    *w = x;
}

void konwertujCiagZnakow(const char* text) {

    int convertedText;
    int i = 0;

    try {
        if (strlen(text) > 15) {
            throw "Tekst jest za dlugi!";
        }
        while (text[i]) {
            if (!isalpha(text[i]))
                throw "Tekst zawiera niepoprawne znaki!";
            i++;
        }

        cout << "Skonwertowana liczba: " << convertedText << endl;
    }
    catch(const char* message) {
        cout << message << endl;
    }
}