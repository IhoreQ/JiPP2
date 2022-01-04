//
// Created by IhoreQ on 04/01/2022.
//

#ifndef SZABLONY_ARRAY_H
#define SZABLONY_ARRAY_H
#include <iostream>

template<typename T, int size>
class Array {

public:
    Array() {
        tab = new T[size];
        length = size;
    }
    ~Array() {
        delete [] tab;
        tab = nullptr;
    }

    void printArray() const {
        for (int i = 0; i < length; ++i)
            std::cout << tab[i] << " ";
        std::cout << std::endl;
    }
    void setNewElement(int index, T value) {
        tab[index] = value;
    }
    void getElement(int index) const {
        return tab[index];
    }

    void insertElements() {
        std::cout << "Podaj " << length << " elementów." << std::endl;
        for (int i = 0; i < length; ++i) {
            std::cout << "Podaj " << i + 1 << " element: ";
            std::cin >> tab[i];
        }
        std::cout << "Wpisano elementy do tablicy!" << std::endl;
    }

private:
    T* tab;
    int length;
};


#endif //SZABLONY_ARRAY_H
