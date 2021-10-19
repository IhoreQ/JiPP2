#include <iostream>
#include "zadania.h"

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