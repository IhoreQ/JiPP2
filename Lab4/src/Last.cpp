#include <iostream>
#include "Last.h"

using namespace std;

Last::Last() {
    this->literki = new char[1024];
    cout << "Konstruktor zostal wykonany" << endl;
}

Last::~Last() {
    delete [] this->literki;
    cout << "Destruktor wykonany" << endl;
}

void Last::pause() {
    int a;
    cout << "Wprowadz cokolwiek ";
    cin >> a;
}