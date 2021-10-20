#include <iostream>
#include <cstring>
#include <cstdlib>
#include "matrixLib.h"

using namespace std;

int main(int argc, char* argv[]) {

    system("clear");

    int** iMatrixA = NULL;
    double** dMatrixA = NULL;
    int** iMatrixB = NULL;
    double** dMatrixB = NULL;
    int** iMultiplyResultMatrix = NULL;
    double** dMultiplyResultMatrix = NULL;
    int** iTransposeResultMatrix = NULL;
    double** dTransposeResultMatrix = NULL;
    int rowsA, colsA, rowsB, colsB;
    int iScalar, iDeterminant;
    double dScalar, dDeterminant;
    unsigned int powerValue;

    if (argc > 2 && argc < 4) {

        if (strcmp(argv[2], "int") != 0 && strcmp(argv[2], "double") != 0) {
            cout << "Niepoprawne uzycie programu!" << endl << "Dowiedz sie jak uzywac wpisujac matricApp -help" << endl;
            exit(1);
        }

        // DODAWANIE MACIERZY
        if (strcmp(argv[1], "addMatrix") == 0) {

            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);
                cout << "Tworzenie macierzy B:" << endl;
                iMatrixB = createMatrix(iMatrixB, &rowsB, &colsB);

                try {
                    if (rowsA != rowsB || colsA != colsB)
                        throw "Wymiary macierzy musza byc takie same!";
                    iMatrixA = addMatrix(iMatrixA, iMatrixB, rowsA, colsA);
                    showMatrix(iMatrixA, rowsA, colsA);
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);
                cout << "Tworzenie macierzy B:" << endl;
                iMatrixB = createMatrix(iMatrixB, &rowsB, &colsB);

                try {
                    if (rowsA != rowsB || colsA != colsB)
                        throw "Wymiary macierzy musza byc takie same!";
                    iMatrixA = addMatrix(iMatrixA, iMatrixB, rowsA, colsA);
                    showMatrix(iMatrixA, rowsA, colsA);
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
        }
        // ODEJMOWANIE MACIERZY
        else if (strcmp(argv[1], "subtractMatrix") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);
                cout << "Tworzenie macierzy B:" << endl;
                iMatrixB = createMatrix(iMatrixB, &rowsB, &colsB);

                try {
                    if (rowsA != rowsB || colsA != colsB)
                        throw "Wymiary macierzy musza byc takie same!";
                    iMatrixA = subtractMatrix(iMatrixA, iMatrixB, rowsA, colsA);
                    showMatrix(iMatrixA, rowsA, colsA);
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);
                cout << "Tworzenie macierzy B:" << endl;
                iMatrixB = createMatrix(iMatrixB, &rowsB, &colsB);

                try {
                    if (rowsA != rowsB || colsA != colsB)
                        throw "Wymiary macierzy musza byc takie same!";
                    iMatrixA = subtractMatrix(iMatrixA, iMatrixB, rowsA, colsA);
                    showMatrix(iMatrixA, rowsA, colsA);
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
        }

        // MNOŻENIE DWÓCH MACIERZY
        else if (strcmp(argv[1], "multiplyMatrix") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);
                cout << "Tworzenie macierzy B:" << endl;
                iMatrixB = createMatrix(iMatrixB, &rowsB, &colsB);

                try {
                    if (colsA != rowsB)
                        throw "Liczba kolumn pierwszej macierzy musi byc rowna liczbie wierszy drugiej";
                    iMultiplyResultMatrix = multiplyMatrix(iMatrixA, iMatrixB, rowsA, colsA, colsB);
                    showMatrix(iMultiplyResultMatrix, rowsA, colsB);
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                dMatrixA = createMatrix(dMatrixA, &rowsA, &colsA);
                cout << "Tworzenie macierzy B:" << endl;
                dMatrixB = createMatrix(dMatrixB, &rowsB, &colsB);

                try {
                    if (colsA != rowsB)
                        throw "Liczba kolumn pierwszej macierzy musi byc rowna liczbie wierszy drugiej";
                    dMultiplyResultMatrix = multiplyMatrix(dMatrixA, dMatrixB, rowsA, colsA, colsB);
                    showMatrix(dMultiplyResultMatrix, rowsA, colsB);
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
        }

        // MNOŻENIE MACIERZY PRZEZ SKALAR
        else if (strcmp(argv[1], "multiplyByScalar") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);

                try {
                    cout << "Podaj wartosc skalara: ";
                    if (scanf("%d", &iScalar) != 1)
                        throw "Wprowadzono bledna wartosc dla skalara!";
                    iMatrixA = multiplyByScalar(iMatrixA, rowsA, colsA, iScalar);
                    showMatrix(iMatrixA, rowsA, colsA);
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                dMatrixA = createMatrix(dMatrixA, &rowsA, &colsA);

                try {
                    cout << "Podaj wartosc skalara: ";
                    if (scanf("%lf", &dScalar) != 1)
                        throw "Liczba kolumn pierwszej macierzy musi byc rowna liczbie wierszy drugiej";
                    dMatrixA = multiplyByScalar(dMatrixA, rowsA, colsA, dScalar);
                    showMatrix(dMatrixA, rowsA, colsA);
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
        }

        // TRANSPOZYCJA MACIERZY
        else if (strcmp(argv[1], "transposeMatrix") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);

                iTransposeResultMatrix = transposeMatrix(iMatrixA, rowsA, colsA);
                showMatrix(iTransposeResultMatrix, colsA, rowsA);
                freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                dMatrixA = createMatrix(dMatrixA, &rowsA, &colsA);

                dTransposeResultMatrix = transposeMatrix(dMatrixA, rowsA, colsA);
                showMatrix(dTransposeResultMatrix, colsA, rowsA);
                freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
            }
        }

        // POTĘGOWANIE MACIERZY
        else if (strcmp(argv[1], "powerMatrix") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                try {
                    insertRowsCols(&rowsA, &colsA);
                    if (rowsA != colsA)
                        throw "Macierz musi byc kwadratowa!";
                    iMatrixA = allocateMatrix(iMatrixA, rowsA, colsA);
                    enterMatrixData(iMatrixA, rowsA, colsA);
                }
                catch (const char* message) {
                    cout << message << endl;
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }

                try {
                    cout << "Podaj stopien potegi: ";
                    if (scanf("%u", &powerValue) != 1)
                        throw "Podano nieprawidlowa wartosc stopnia potegi!";
                    iMatrixA = powerMatrix(iMatrixA, rowsA, colsA, powerValue);
                    showMatrix(iMatrixA, rowsA, colsA);
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                try {
                    insertRowsCols(&rowsA, &colsA);
                    if (rowsA != colsA)
                        throw "Macierz musi byc kwadratowa!";
                    dMatrixA = allocateMatrix(dMatrixA, rowsA, colsA);
                    enterMatrixData(dMatrixA, rowsA, colsA);
                }
                catch (const char* message) {
                    cout << message << endl;
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }

                try {
                    cout << "Podaj stopien potegi: ";
                    if (scanf("%u", &powerValue) != 1)
                        throw "Podano nieprawidlowa wartosc stopnia potegi!";
                    dMatrixA = powerMatrix(dMatrixA, rowsA, colsA, powerValue);
                    showMatrix(dMatrixA, rowsA, colsA);
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                }
                catch(const char* message) {
                    cout << message << endl;
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }
            }
        }

        // WYZNACZNIK MACIERZY
        else if (strcmp(argv[1], "determinantMatrix") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                try {
                    insertRowsCols(&rowsA, &colsA);
                    if (rowsA != colsA)
                        throw "Macierz musi byc kwadratowa!";
                    iMatrixA = allocateMatrix(iMatrixA, rowsA, colsA);
                    enterMatrixData(iMatrixA, rowsA, colsA);
                }
                catch (const char *message) {
                    cout << message << endl;
                    freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }

                int *colsVector = new int[rowsA];

                for (int i = 0; i < rowsA; ++i)
                    colsVector[i] = i;

                iDeterminant = determinantMatrix(iMatrixA, rowsA, colsVector, 0);
                showMatrix(iMatrixA, rowsA, colsA);
                cout << "Wyznacznik macierzy: " << iDeterminant << endl;
                delete[] colsVector;
                freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);

            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                try {
                    insertRowsCols(&rowsA, &colsA);
                    if (rowsA != colsA)
                        throw "Macierz musi byc kwadratowa!";
                    dMatrixA = allocateMatrix(dMatrixA, rowsA, colsA);
                    enterMatrixData(dMatrixA, rowsA, colsA);
                }
                catch (const char* message) {
                    cout << message << endl;
                    freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
                    exit(1);
                }

                int* colsVector = new int [rowsA];

                for (int i = 0; i < rowsA; ++i)
                    colsVector[i] = i;

                dDeterminant = determinantMatrix(dMatrixA, rowsA, colsVector, 0);
                showMatrix(dMatrixA, rowsA, colsA);
                cout << "Wyznacznik macierzy: " << dDeterminant << endl;
                delete [] colsVector;
                freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);

            }
        }

        // CZY MACIERZ JEST DIAGONALNA

        else if (strcmp(argv[1], "matrixIsDiagonal") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);

                showMatrix(iMatrixA, rowsA, colsA);
                if (matrixIsDiagonal(iMatrixA, rowsA, colsA))
                    cout << "Macierz jest diagonalna." << endl;
                else
                    cout << "Macierz nie jest diagonalna." << endl;
                freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                dMatrixA = createMatrix(dMatrixA, &rowsA, &colsA);

                showMatrix(dMatrixA, rowsA, colsA);
                if (matrixIsDiagonal(dMatrixA, rowsA, colsA))
                    cout << "Macierz jest diagonalna." << endl;
                else
                    cout << "Macierz nie jest diagonalna." << endl;
                freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
            }
        }

        // SORTOWANIE WIERSZY MACIERZY

        else if (strcmp(argv[1], "sortRowsInMatrix") == 0) {
            if (strcmp(argv[2], "int") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                iMatrixA = createMatrix(iMatrixA, &rowsA, &colsA);

                iMatrixA = sortRowsInMatrix(iMatrixA, rowsA, colsA);
                showMatrix(iMatrixA, rowsA, colsA);
                freeAll(iMatrixA, iMatrixB, iMultiplyResultMatrix, iTransposeResultMatrix, rowsA, colsA, rowsB);
            }
            else if (strcmp(argv[2], "double") == 0) {
                cout << "Tworzenie macierzy A:" << endl;
                dMatrixA = createMatrix(dMatrixA, &rowsA, &colsA);

                dMatrixA = sortRowsInMatrix(dMatrixA, rowsA, colsA);
                showMatrix(dMatrixA, rowsA, colsA);
                freeAll(dMatrixA, dMatrixB, dMultiplyResultMatrix, dTransposeResultMatrix, rowsA, colsA, rowsB);
            }
        }
        else if (strcmp(argv[2], "help") == 0)  {
            showHelp();
        }
    }
    else {
        cout << "Niepoprawne uzycie programu!" << endl << "Dowiedz sie jak uzywac wpisujac matrixApp help" << endl;
    }

    return 0;
}
