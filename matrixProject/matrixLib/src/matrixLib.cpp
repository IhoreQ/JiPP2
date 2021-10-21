#include "../include/matrixLib.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int** allocateMatrix(int** matrix, int rows, int cols) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int [cols];
    return matrix;
}

double** allocateMatrix(double** matrix, int rows, int cols) {
    matrix = new double* [rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new double [cols];
    return matrix;
}


int** createMatrix(int** matrix, int *rows, int *cols) {
    insertRowsCols(rows, cols);
    matrix = allocateMatrix(matrix, *rows, *cols);
    matrix = enterMatrixData(matrix, *rows, *cols);

    system("clear");
    return matrix;
}

double** createMatrix(double** matrix, int *rows, int *cols) {
    insertRowsCols(rows, cols);
    matrix = allocateMatrix(matrix, *rows, *cols);
    matrix = enterMatrixData(matrix, *rows, *cols);

    system("clear");
    return matrix;
}


void freeMatrix(int** matrix, int rows) {

    for (int i = 0; i < rows; ++i) {
        delete [] matrix[i];
        matrix[i] = NULL;
    }
    delete [] matrix;
    matrix = NULL;
}

void freeMatrix(double** matrix, int rows) {

    for (int i = 0; i < rows; ++i) {
        delete [] matrix[i];
        matrix[i] = NULL;
    }
    delete [] matrix;
    matrix = NULL;
}


void freeAll(int** matrixA, int** matrixB, int** multiplyResult, int** transposeResult, int rowsA, int colsA, int rowsB) {

    if (matrixA)
        freeMatrix(matrixA, rowsA);
    if (matrixB)
        freeMatrix(matrixB, rowsB);
    if (multiplyResult)
        freeMatrix(multiplyResult, rowsA);
    if (transposeResult)
        freeMatrix(transposeResult, colsA);

}

void freeAll(double** matrixA, double** matrixB, double** multiplyResult, double** transposeResult, int rowsA, int colsA, int rowsB) {

    if (matrixA)
        freeMatrix(matrixA, rowsA);
    if (matrixB)
        freeMatrix(matrixB, rowsB);
    if (multiplyResult)
        freeMatrix(multiplyResult, rowsA);
    if (transposeResult)
        freeMatrix(transposeResult, colsA);
}

void insertRowsCols(int* rows, int* cols) {

    cout << "Podaj ilosc wierszy macierzy: ";
    try {
        if (scanf("%d", rows) != 1 || *rows < 0)
            throw "Blednie podano ilosc wierszy!";
    }
    catch (const char* message) {
        cout << message << endl;
        exit(1);
    }

    cout << "Podaj ilosc kolumn macierzy: ";

    try {
        if (scanf("%d", cols) != 1 || *cols < 0)
            throw "Blednie podano ilosc kolumn!";
    }
    catch (const char* message) {
        cout << message << endl;
        exit(1);
    }
}

void showMatrix(int** matrix, int rows, int cols, const char* text) {

    cout << text << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void showMatrix(double** matrix, int rows, int cols, const char* text) {

    cout << text << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}


int** enterMatrixData(int** matrix, int rows, int cols) {

    cout << "Wpisz wartosci typu int." << endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Podaj wartosc dla %d wiersza i %d kolumny: ", i + 1, j + 1);
            try {
                if (scanf("%d", &matrix[i][j]) < 1)
                    throw "Wprowadzona wartosc jest bledna!";
            }
            catch(const char* message) {
                cout << message << endl;
                freeMatrix(matrix, rows);
                exit(1);
            }
        }
    }
    return matrix;
}

double** enterMatrixData(double** matrix, int rows, int cols) {

    cout << "Wpisz wartosci typu double." << endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Podaj wartosc dla %d wiersza i %d kolumny: ", i + 1, j + 1);
            try {
                if (scanf("%lf", &matrix[i][j]) < 1)
                    throw "Wprowadzona wartosc jest bledna!";
            }
            catch(const char* message) {
                cout << message << endl;
                freeMatrix(matrix, rows);
                exit(1);
            }
        }
    }
    return matrix;
}


int** addMatrix(int** matrixA, int** matrixB, int rows, int cols) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixA[i][j] += matrixB[i][j];
        }
    }
    return matrixA;
}

double** addMatrix(double** matrixA, double** matrixB, int rows, int cols) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixA[i][j] += matrixB[i][j];
        }
    }
    return matrixA;
}


int** subtractMatrix(int** matrixA, int** matrixB, int rows, int cols) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixA[i][j] -= matrixB[i][j];
        }
    }
    return matrixA;
}

double** subtractMatrix(double** matrixA, double** matrixB, int rows, int cols) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixA[i][j] += matrixB[i][j];
        }
    }
    return matrixA;
}


int** multiplyMatrix(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {

    int** resultMatrix = NULL;
    resultMatrix = allocateMatrix(resultMatrix, rowsA, colsB);
    int suma = 0;

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            for (int k = 0; k < colsA; ++k)
                suma += matrixA[i][k] * matrixB[k][j];
            resultMatrix[i][j] = suma;
            suma = 0;
        }
    }
    return resultMatrix;
}

double** multiplyMatrix(double** matrixA, double** matrixB, int rowsA, int colsA, int colsB) {

    double** resultMatrix = NULL;
    resultMatrix = allocateMatrix(resultMatrix, rowsA, colsB);
    double suma = 0;

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            for (int k = 0; k < colsA; ++k)
                suma += matrixA[i][k] * matrixB[k][j];
            resultMatrix[i][j] = suma;
            suma = 0.0;
        }
    }

    return resultMatrix;
}


int** multiplyByScalar(int** matrixA, int rows, int cols, int scalar) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixA[i][j] *= scalar;
        }
    }
    return matrixA;
}

double** multiplyByScalar(double** matrixA, int rows, int cols, double scalar) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixA[i][j] *= scalar;
        }
    }
    return matrixA;
}


int** transposeMatrix(int** matrixA, int rows, int cols) {

    int** resultMatrix = NULL;
    resultMatrix = allocateMatrix(resultMatrix, cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultMatrix[j][i] = matrixA[i][j];
        }
    }
    return resultMatrix;
}

double** transposeMatrix(double** matrixA, int rows, int cols) {

    double** resultMatrix = NULL;
    resultMatrix = allocateMatrix(resultMatrix, cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resultMatrix[j][i] = matrixA[i][j];
        }
    }
    return resultMatrix;
}


int** powerMatrix(int** matrixA, int rows, int cols, unsigned int exponent) {

    int** tempMatrix = allocateMatrix(tempMatrix, rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            tempMatrix[i][j] = matrixA[i][j];
    }

    for (int i = 0; i < exponent - 1; ++i) {
        matrixA = multiplyMatrix(matrixA, tempMatrix, rows, cols, cols);
    }
    freeMatrix(tempMatrix, rows);
    return matrixA;
}

double** powerMatrix(double** matrixA, int rows, int cols, unsigned int exponent) {

    double** tempMatrix = allocateMatrix(tempMatrix, rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            tempMatrix[i][j] = matrixA[i][j];
    }

    for (int i = 0; i < exponent - 1; ++i) {
        matrixA = multiplyMatrix(matrixA, tempMatrix, rows, cols, cols);
    }
    freeMatrix(tempMatrix, rows);
    return matrixA;
}


int determinantMatrix(int** matrixA, int rows, int* colsVector, int startingRow) {

    int sign, sum, col;
    int* subVector = NULL;

    if (rows == 1)
        return matrixA[startingRow][colsVector[0]];
    else {
        subVector = new int [rows - 1];
        sum = 0;
        sign = 1;

        for (int i = 0; i < rows; ++i) {
            col = 0;
            for (int j = 0; j < rows - 1; ++j) {
                if (col == i)
                    col++;
                subVector[j] = colsVector[col++];
            }

            sum += sign * matrixA[startingRow][colsVector[i]] * determinantMatrix(matrixA, rows - 1, subVector, startingRow + 1);
            sign = -sign;
        }
        delete [] subVector;
        return sum;
    }
}

double determinantMatrix(double** matrixA, int rows, int* colsVector, int startingRow) {

    int sign, col;
    double sum;
    int* subVector = NULL;

    if (rows == 1)
        return matrixA[startingRow][colsVector[0]];
    else {
        subVector = new int [rows - 1];
        sum = 0;
        sign = 1;

        for (int i = 0; i < rows; ++i) {
            col = 0;
            for (int j = 0; j < rows - 1; ++j) {
                if (col == i)
                    col++;
                subVector[j] = colsVector[col++];
            }

            sum += sign * matrixA[startingRow][colsVector[i]] * determinantMatrix(matrixA, rows - 1, subVector, startingRow + 1);
            sign = -sign;
        }
        delete [] subVector;
        return sum;
    }
}


bool matrixIsDiagonal(int** matrixA, int rows, int cols) {

    if (rows != cols)
        return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i != j && matrixA[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool matrixIsDiagonal(double** matrixA, int rows, int cols) {

    if (rows != cols)
        return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i != j && matrixA[i][j] != 0)
                return false;
        }
    }
    return true;
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}


void sortRow(int* tab, int cols) {

    for (int i = 0; i < cols - 1; ++i) {
        for (int j = 0; j < cols - i - 1; ++j) {
            if (tab[j] > tab[j + 1])
                swap(tab[j], tab[j + 1]);
        }
    }
}

void sortRow(double* tab, int cols) {

    for (int i = 0; i < cols - 1; ++i) {
        for (int j = 0; j < cols - i - 1; ++j) {
            if (tab[j] > tab[j + 1])
                swap(tab[j], tab[j + 1]);
        }
    }
}


int** sortRowsInMatrix(int** matrixA, int rows, int cols) {

    for (int i = 0; i < rows; ++i)
        sortRow(matrixA[i], cols);

    return matrixA;
}

double** sortRowsInMatrix(double** matrixA, int rows, int cols) {

    for (int i = 0; i < rows; ++i)
        sortRow(matrixA[i], cols);

    return matrixA;
}


void showHelp() {

    system("clear");

    cout << "------------------------------------------" << endl;
    cout << "Program wykonujacy operacje na macierzach." << endl;
    cout << "------------------------------------------" << endl;
    cout << "matrixApp [nazwa dzialania] [typ danych]" << endl << endl;

    cout << "Po wczytaniu programu, poprosi on o wpisanie liczby wierszy oraz kolumn macierzy." << endl;
    cout << "W przypadku potrzeby wykonania dzialania na dwoch macierzach, program poprosi o wprowadzenie danych dla drugiej macierzy." << endl << endl;

    cout << "Typy danych: " << endl << "   int - operacje na liczbach calkowitych" << endl << "   double - operacje na liczbach zmiennoprzecinkowych" << endl << endl;

    cout << "Dzialania: " << endl;
    cout << "   addMatrix - dodawanie do macierzy A macierzy B" << endl;
    cout << "   subtractMatrix - odejmowanie od macierzy A macierzy B" << endl;
    cout << "   multiplyMatrix - mnozenie macierzy A i macierzy B, wymagana jest taka sama liczba kolumn macierzy A " << endl;
    cout << "   multiplyByScalar - mnozenie macierzy przez skalar podawany w trakcie dzialania programu" << endl;
    cout << "   transposeMatrix - transpozycja macierzy" << endl;
    cout << "   powerMatrix - potegowanie macierzy, stopien potegi podawany w trakcie dzialania programu" << endl;
    cout << "   determinantMatrix - obliczanie wyznacznika macierzy" << endl;
    cout << "   matrixIsDiagonal - sprawdzenie, czy macierz jest diagonalna (czy kazdy jej element poza przekatna jest rowny 0" << endl;
    cout << "   sortRowsInMatrix - sortowanie rosnaca kazdego wiersza macierzy" << endl << endl;

    cout << "Przyklad zastosowania: "<< endl << "   matrixApp addMatrix double" << endl;
}