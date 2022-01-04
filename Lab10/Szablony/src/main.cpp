#include <iostream>
#include "../include/Array.h"
#include "../include/Vector.h"

template<typename Type>
Type minValue(Type a, Type b) {
    return (a <= b) ? a : b;
}

template<typename Type>
Type maxValue(Type a, Type b) {
    return (a >= b) ? a : b;
}

template<typename Type>
void printArray(Type* a, int arraySize) {
    for (int i = 0; i < arraySize; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

template<typename Type>
void printMatrix(Type a[], int rowsN, int colsN) {
    for (int i = 0; i < rowsN; ++i) {
        for (int j = 0; j < colsN; ++j)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
}

int main() {

    /* ----------------------- ZADANIE 1. ----------------------- */

    std::cout << "----------------------- ZADANIE 1. -----------------------" << std::endl;
    char ten = 'A';
    int intA[5] = {1, 2, 3, 4, 5};
    char** charM = nullptr;
    charM = new char* [3];
    for (int i = 0; i < 3; ++i)
        charM[i] = new char [3];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            charM[i][j] = ten++;

    std::cout << minValue<int>(3, 5) << std::endl;
    std::cout << maxValue<char>('A', 'Z') << std::endl;
    printArray(intA, 5);
    printMatrix(charM, 3, 3);

    for (int i = 0; i < 3; ++i)
        delete [] charM[i];
    delete [] charM;
    charM = nullptr;

    /* ----------------------- ZADANIE 2. ----------------------- */

    std::cout << "----------------------- ZADANIE 2. -----------------------" << std::endl;
    Array<char, 5> tab;

    //tab.insertElements();
    //tab.printArray();

    /* ----------------------- ZADANIE 3. ----------------------- */

    std::cout << "----------------------- ZADANIE 3. -----------------------" << std::endl;

    Vector<int> wektorek;

    wektorek.push_back(1);
    wektorek.push_back(2);
    wektorek.push_back(3);
    wektorek.push_back(4);
    wektorek.push_back(5);
    wektorek.push_back(6);
    wektorek.print();
    wektorek.pop_back();
    wektorek.pop_back();
    wektorek.pop_back();
    wektorek.print();

    std::cout << "Wskaźnik do tablicy: " << std::endl;

    int* pWektorek = wektorek.get_pointer();

    for (int i = 0; i < wektorek.getLength(); ++i)
        std::cout << pWektorek[i] << " ";
    std::cout << std::endl;

    return 0;
}
