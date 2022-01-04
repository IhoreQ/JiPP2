//
// Created by IhoreQ on 04/01/2022.
//

#ifndef SZABLONY_VECTOR_H
#define SZABLONY_VECTOR_H

#include <cstring>

template<typename T>
class Vector {

public:
    Vector() {
        length = 0;
        size = 0;
        tab = nullptr;
    }
    ~Vector() {
        delete [] tab;
        tab = nullptr;
    }

    void push_back(T element) {

        T* newTab = nullptr;

        if (length == 0) {
            tab = new T [1];
            tab[0] = element;
            length++;
            size++;
        }
        else if (length >= size) {
            size *= 2;
            newTab = new T[size];
            memcpy(newTab, tab, length * sizeof(T));
            delete [] tab;
            tab = newTab;
            tab[length++] = element;
        }
        else {
            tab[length++] = element;
        }
    }

    void pop_back() {
        if (length > 0) {
            T* newTab = new T[size];
            memcpy(newTab, tab, (length - 1) * sizeof(T));
            delete [] tab;
            tab = newTab;
            length--;
        }
    }

    T* get_pointer() {
        return tab;
    }

    int getLength() {
        return length;
    }

    void print() {
        for (int i = 0; i < length; ++i)
            std::cout << tab[i] << " ";
        std::cout << std::endl;
    }

private:
    T* tab;
    int size;
    int length;
};

#endif //SZABLONY_VECTOR_H
