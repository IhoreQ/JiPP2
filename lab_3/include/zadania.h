#include <iostream>
using namespace std;

// 1. Liczenie pola figury

double pole(double a, double b);
int pole(int a, int b);
double pole(double a, double b, double c);
int pole(int a, int b, int c);

// 2. Losowanie liczby z przedziału <a;b>

int losuj(int a, int b);

// 3. Najwieksza wartosc tablicy
int maxTablica(int* tab, int tabSize);

// 4. Odwracanie kolejnosci tablicy
void odwrocKolejnoscTablicy(int* tab, int tabSize);

// 5. Srednia wskaznikow
void liczSrednia(double* a, double* b, double* wynik);

// 6. Wypisanie elementow wiekszych od 50 na wskaznikach
void wypiszElementy(int* tab, int tabSize);

// 7. Sortowanie zmiennych

void zamiana(int* a, int* b);
void sortujElementy(int* a, int* b, int* c);

// 8. Przypisanie do wskaznika na zmienna zmiennej

void wpisanieWskaznikaWZmienna(int x, int* w);

// 10. Konwersja ciągu znaków

void konwertujCiagZnakow(const char* text);