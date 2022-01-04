#ifndef WYPOZYCZALNIAFILMOW_USER_H
#define WYPOZYCZALNIAFILMOW_USER_H

#include "Film.h"
#include "Series.h"
#include <vector>

class User {

public:
    // Konstruktory / destruktory
    User();
    User(const std::string& newLogin, const std::string& newPassword);
    User(const std::string& loadLogin, const std::string& loadPassword, bool loadLoyaltyCard, unsigned loadBorrowedFilmsNumber, unsigned loadBorrowedSeriesNumber, unsigned loadReviewsNumber, const std::vector<Film*>& loadBorrowedFilms, const std::vector<Film*>& loadBorrowedFilmsHistory, const std::vector<Series*>& loadBorrowedSeries, const std::vector<Series*>& loadBorrowedSeriesHistory);
    ~User();

    // Gettery
    std::string getLogin() const;
    std::string getPassword() const;
    bool getLoyaltyCardInfo() const;
    unsigned getBorrowedFilmsNumber() const;
    unsigned getBorrowedSeriesNumber() const;
    unsigned getReviewsNumber() const;

    // Wyświetlanie informacji
    void printBorrowedFilms();
    void printBorrowedFilmsHistory();
    void printBorrowedSeries();
    void printBorrowedSeriesHistory();

    // Funkcje użytkownika
    void borrowFilm(Film* film);
    void borrowSeries(Series* series);
    void giveBackFilm(const std::string& filmName);
    void giveBackSeries(const std::string& seriesName);
    void applyForLoyaltyCard();

    // Tworzenie / rejestracja / zapis do pliku
    void create();
    void registerNewUser();
    void saveToFile(); //TODO
    void loginToRental(const char* eLogin, const char* ePassword);

    // Metody pomocnicze
    bool isFilmBorrowed(const std::string& title);
    bool wasFilmBorrowed(const std::string &title);
    bool isSeriesBorrowed(const std::string& title);
    bool wasSeriesBorrowed(const std::string &title);

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
