// Plik zawiera wszystkie funkcjonalności związanie z użytkownikiem

#ifndef WYPOZYCZALNIAFILMOW_USER_H
#define WYPOZYCZALNIAFILMOW_USER_H

#include "Film.h"
#include "Series.h"
#include <vector>

class User {

public:
    // Konstruktor
    User();
    // Desktruktor
    ~User();

    // Pobranie loginu
    std::string getLogin() const;
    // Pobranie hasła
    std::string getPassword() const;
    // Pobranie informacji o karcie stałego klienta
    bool getLoyaltyCardInfo() const;
    // Pobranie informacji o liczbie wypożyczonych filmów
    unsigned getBorrowedFilmsNumber() const;
    // Pobranie informacji o liczbie wypożyczonych seriali
    unsigned getBorrowedSeriesNumber() const;
    // Pobranie informacji o liczbie dodanych recenzji
    unsigned getReviewsNumber() const;
    // Ustawienie wartości dla karty stałego klienta
    void setLoyaltyCard(bool flag);
    // Ustawienie wartości dla ilości dodanych recenzji
    void setReviewsNumber(unsigned number);
    // Ustawienie wartości dla liczby wypożyczonych filmów
    void setBorrowedFilmsNumber(unsigned number);
    // Ustawienie wartości dla liczby wypożyczonych seriali
    void setBorrowedSeriesNumber(unsigned number);

    // Wyświetlanie wypożyczonych filmów
    void printBorrowedFilms() const;
    // Wyświetlenie historii wypożyczonych filmów
    void printBorrowedFilmsHistory() const;
    // Wyświetlenie wypożyczonych seriali
    void printBorrowedSeries() const;
    // Wyświetlenie historii wypożyczonych seriali
    void printBorrowedSeriesHistory() const;
    // Sprawdzenie czy kontener na filmy i seriale jest pusty
    bool checkFilmsAndSeriesEmpty() const;
    // Sprawdzenie czy kontener historii filmów i seriali jest pusty
    bool checkFilmsAndSeriesHistoryEmpty() const;

    // Metoda dodająca wskaźnik do filmu do kontenera użytkownika
    void borrowFilm(Film* film);
    // Metoda dodająca wskaźnik do serialu do kontenera użytkownika
    void borrowSeries(Series* series);
    // Metoda usuwająca wskaźnik do filmu z kontenera
    void giveBackFilm(const std::string& filmName);
    // Metoda usuwająca wskaźnik do serialu z kontenera
    void giveBackSeries(const std::string& seriesName);
    // Zwiększenie liczby dodanych recenzji
    void incrementReviewsNumber();

    // Tworzenie użytkownika
    void create();
    // Rejestracja użytkownika
    void registerNewUser();
    // Zapisywanie danych użytkownika do pliku
    void saveToFile();
    // Logowanie użytkownika do wypożyczalni
    void loginToRental(const char* eLogin, const char* ePassword);

    // Pobranie informacji czy film jest wypożyczony
    bool isFilmBorrowed(const std::string& title);
    // Pobranie informacji czy film był już wypożyczany
    bool wasFilmBorrowed(const std::string& title);
    // Pobranie informacji czy serial jest wypożyczony
    bool isSeriesBorrowed(const std::string& title);
    // Pobranie informacji czy serial był już wypożyczany
    bool wasSeriesBorrowed(const std::string& title);
    // Sprawdzenie czy kontener z historią wypożyczonych filmów jest pusty
    bool isFilmHistoryVectorEmpty();
    // Sprawdzenie czy kontener z historią wypożyczonych seriali jest pusty
    bool isSeriesHistoryVectorEmpty();
    // Załadowanie filmu do kontenera wypożyczonych (z pliku)
    void loadFilmToBorrowed(Film* film);
    // Załadowanie serialu do kontenera wypożyczonych (z pliku)
    void loadSeriesToBorrowed(Series* series);
    // Załadowanie filmu do kontenera historii wypożyczonych (z pliku)
    void loadFilmToHistory(Film* film);
    // Załadowanie serialu do kontenera historii wypożyczonych (z pliku)
    void loadSeriesToHistory(Series* series);

private:
    std::string login;
    std::string password;
    bool loyaltyCard;
    unsigned borrowedFilmsNumber;
    unsigned borrowedSeriesNumber;
    unsigned reviewsNumber;
    std::vector<Film*> borrowedFilms;
    std::vector<Film*> borrowedFilmsHistory;
    std::vector<Series*> borrowedSeries;
    std::vector<Series*> borrowedSeriesHistory;
};

#endif //WYPOZYCZALNIAFILMOW_USER_H
