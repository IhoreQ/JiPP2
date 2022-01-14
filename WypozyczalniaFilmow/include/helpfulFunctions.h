//
// Created by IhoreQ on 02/01/2022.
//

#ifndef WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H
#define WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H

#include <vector>

void checkInput(int& option, int leftBound, int rightBound);
bool findUser(const std::string& userLogin);
std::vector<std::string> breakTheLine(const std::string& line);

template<typename T>
T countAverage(T oldAverage, unsigned newValue) {
    return ((oldAverage + newValue) / 2);
}

#endif //WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H
