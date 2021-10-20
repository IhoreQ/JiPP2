#ifndef MATRIXLIB_LIBRARY_H
#define MATRIXLIB_LIBRARY_H

// dynamiczna alokacja macierzy
int** allocateMatrix(int** matrix, int rows, int cols);
double** allocateMatrix(double** matrix, int rows, int cols);

// tworzenie macierzy
int** createMatrix(int** matrix, int* rows, int* cols);
double** createMatrix(double** matrix, int *rows, int *cols);

// usuwanie macierzy z pamieci
void freeMatrix(int** matrix, int rows);
void freeMatrix(double** matrix, int rows);

void freeAll(int** matrixA, int** matrixB, int** multiplyResult, int** transposeResult, int rowsA, int colsA, int rowsB);
void freeAll(double** matrixA, double** matrixB, double** multiplyResult, double** transposeResult, int rowsA, int colsA, int rowsB);

// wprowadzanie ilosci wierszy i kolumn
void insertRowsCols(int* rows, int* cols);

// wyswietlenie macierzy na ekran
void showMatrix(int** matrix, int rows, int cols);
void showMatrix(double** matrix, int rows, int cols);

// wprowadzenie danych do macierzy
int** enterMatrixData(int** matrix, int rows, int cols);
double** enterMatrixData(double** matrix, int rows, int cols);

// dodawanie macierzy A do macierzy B
int** addMatrix(int** matrixA, int** matrixB, int rows, int cols);
double** addMatrix(double** matrixA, double** matrixB, int rows, int cols);

// odejmowanie od macierzy A macierzy B
int** subtractMatrix(int** matrixA, int** matrixB, int rows, int cols);
double** subtractMatrix(double** matrixA, double** matrixB, int rows, int cols);

// mnożenie macierzy A i macierzy B
int** multiplyMatrix(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB);
double** multiplyMatrix(double** matrixA, double** matrixB, int rowsA, int colsA, int colsB);

// mnożenie macierzy A przez skalar
int** multiplyByScalar(int** matrixA, int rows, int cols, int scalar);
double** multiplyByScalar(double** matrixA, int rows, int cols, double scalar);

// Transponowanie macierzy
int** transposeMatrix(int** matrixA, int rows, int cols);
double** transposeMatrix(double** matrixA, int rows, int cols);

// Potęgowanie macierzy
int** powerMatrix(int** matrixA, int rows, int cols, unsigned int exponent);
double** powerMatrix(double** matrixA, int rows, int cols, unsigned int exponent);

// Tworzenie podmacierzy

int** subMatrixCreate(int** matrix, int rows);

// Obliczanie wyznacznika macierzy
int determinantMatrix(int** matrixA, int rows, int* colsVector, int startingRow);
double determinantMatrix(double** matrixA, int rows, int* colsVector, int startingRow);

// Sprawdzenie czy macierz jest diagonalna
bool matrixIsDiagonal(int** matrixA, int rows, int cols);
bool matrixIsDiagonal(double** matrixA, int rows, int cols);

// Zamiana wartości dwóch elementów
void swap(int& a, int& b);
void swap(double& a, double& b);

// Sortowanie bąbelkowe wiersza
void sortRow(int* tab, int cols);
void sortRow(double* tab, int cols);

// Sortowanie wszystkich wierszy macierzy
int** sortRowsInMatrix(int** matrixA, int rows, int cols);
double** sortRowsInMatrix(double** matrixA, int rows, int cols);

// Wyświetlenie dokumentacji
void showHelp();

#endif //MATRIXLIB_LIBRARY_H