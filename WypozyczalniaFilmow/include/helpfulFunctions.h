//
// Created by IhoreQ on 02/01/2022.
//

#ifndef WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H
#define WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H

#include <vector>

// Funkcja sprawdzająca czy podana przez użytkownika wartość - option mieści się w przedziale <leftBound, rightBound>
void checkInput(int& option, int leftBound, int rightBound);
// Funkcja szukająca użytkownika w pliku Users.csv
bool findUser(const std::string& userLogin);
// Funkcja rozbijająca linię z pliku csv na osobne wartości z kolumn
std::vector<std::string> breakTheLine(const std::string& line);

// Szablon funkcji liczącej średnią arytmetyczną dwóch wartości
template<typename T>
T countAverage(T oldAverage, unsigned newValue) {
    return ((oldAverage + newValue) / 2);
}

#endif //WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H
