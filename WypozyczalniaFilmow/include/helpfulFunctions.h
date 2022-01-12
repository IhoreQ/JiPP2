//
// Created by IhoreQ on 02/01/2022.
//

#ifndef WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H
#define WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H

#include <vector>

void checkInput(int& option, int leftBound, int rightBound);
bool findUser(const std::string& userLogin);
std::vector<std::string> breakTheLine(const std::string& line);

#endif //WYPOZYCZALNIAFILMOW_HELPFULFUNCTIONS_H
