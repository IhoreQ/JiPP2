#ifndef CSVLIB_LIBRARY_H
#define CSVLIB_LIBRARY_H

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <exception>

// Funkcjonalności:

// 1. Wczytaj dane z pliku
std::vector<std::vector<std::string>> csvRead(std::fstream* file);
// 2. Zapisz dane do pliku
void csvWrite(std::fstream* file);
// 3. Modyfikuj dane w pliku
void csvEdit(const std::string& oldValue, const std::string& newValue);

// Klasa wyjątku

class eX : public std::exception {

public:
    explicit eX(char* exceptionText, int errorCode): exceptionText(exceptionText), errorCode(errorCode) {}

    const char* what() {
        if (errorCode < 3) {
            std::cout << "Błąd krytyczny!\n";
        }
        else if (errorCode < 10) {
            std::cout << "Poważny błąd!\n";
        }
        else if (errorCode < 20) {
            std::cout << "Ostrzeżenie!\n";
        }

        std::cout << "Kod numer: " << errorCode << std::endl;

        return exceptionText;
    }

private:
    char* exceptionText;
    int errorCode;
};

#endif //CSVLIB_LIBRARY_H
