#include <iostream>
#include <vector>
#include <fstream>
#include "../include/User.h"
#include "../include/helpfulFunctions.h"

using namespace std;

// Konstruktory

User::User() {
    login = "";
    password = "";
    loyaltyCard = false;
    borrowedFilmsNumber = 0;
    borrowedSeriesNumber = 0;
    reviewsNumber = 0;
}

User::~User() {
    //saveToFile();
}

string User::getLogin() const {
    return login;
}

string User::getPassword() const {
    return password;
}

bool User::getLoyaltyCardInfo() const {
    return loyaltyCard;
}

unsigned User::getBorrowedFilmsNumber() const {
    return borrowedFilmsNumber;
}

unsigned User::getBorrowedSeriesNumber() const {
    return borrowedSeriesNumber;
}

unsigned User::getReviewsNumber() const {
    return reviewsNumber;
}

void User::printBorrowedFilms() const { // TODO

    if (borrowedFilms.empty())
        cout << "Brak wypożyczonych filmów!" << endl;
    else {
        string dashes(54, '-');
        cout << "Wypożyczone filmy:" << endl;
        cout << "Lp.\tNazwa\tGatunek\tData publikacji" << endl;
        cout << dashes << endl;
        int i = 1;
        for (auto& video : borrowedFilms) {
            cout << i++ << ".\t" << *video << endl;
        }
    }
}

void User::printBorrowedFilmsHistory() const { // TODO

    if (borrowedFilmsHistory.empty())
        cout << "Brak wypożyczonych filmów w historii!" << endl;
    else {
        string dashes(54, '-');
        cout << "Historia wypożyczonych filmów:" << endl;
        cout << "Lp.\tNazwa\tGatunek\tData publikacji" << endl;
        cout << dashes << endl;
        int i = 1;
        for (auto& video : borrowedFilmsHistory) {
            cout << i++ << ".\t" << *video << endl;
        }
    }
}
void User::printBorrowedSeries() const { // TODO

    if (borrowedSeries.empty())
        cout << "Brak wypożyczonych seriali!" << endl;
    else {
        string dashes(100, '-');
        cout << "Wypożyczone seriale:" << endl;
        cout << "Lp.\tNazwa\tGatunek\tData publikacji\tLiczba odcinków\tLiczba sezonów" << endl;
        cout << dashes << endl;
        int i = 1;
        for (auto& video : borrowedSeries) {
            cout << i++ << ".\t" << *video << endl;
        }
    }
}

void User::printBorrowedSeriesHistory() const { // TODO

    if (borrowedSeriesHistory.empty())
        cout << "Brak wypożyczonych seriali w historii!" << endl;
    else {
        string dashes(100, '-');
        cout << "Historia wypożyczonych seriali:" << endl;
        cout << "Lp.\tNazwa\tGatunek\tData publikacji\tLiczba odcinków\tLiczba sezonów" << endl;
        cout << dashes << endl;
        int i = 1;
        for (auto& video : borrowedSeriesHistory) {
            cout << i++ << ".\t" << *video << endl;
        }
    }
}

void User::borrowFilm(Film* film) {
    borrowedFilms.push_back(film);
    if (!(wasFilmBorrowed(film->getName())))
        borrowedFilmsHistory.push_back(film);
    borrowedFilmsNumber++;
}

void User::borrowSeries(Series* series) {
    borrowedSeries.push_back(series);
    if (!(wasSeriesBorrowed(series->getName())))
        borrowedSeriesHistory.push_back(series);
    borrowedSeriesNumber++;
}

void User::giveBackFilm(const string& filmName) {
    vector<Film*>::iterator item;

    for (item = borrowedFilms.begin(); item != borrowedFilms.end(); ++item) {
        if ((*item)->getName() == filmName) {
            borrowedFilms.erase(item);
            break;
        }
    }
}

void User::giveBackSeries(const string& seriesName) {
    vector<Series*>::iterator item;

    for (item = borrowedSeries.begin(); item != borrowedSeries.end(); ++item) {
        if ((*item)->getName() == seriesName) {
            borrowedSeries.erase(item);
            break;
        }
    }
}

void User::applyForLoyaltyCard() {
    if (loyaltyCard) {
        cout << "Już posiadasz kartę stałego klienta!" << endl;
    } else {

        cout << "Aby założyć kartę stałego klienta musisz spełniać następujące warunki:" << endl << "1. Posiadać przynajmniej 20 wypożyczonych filmów lub seriali"
        << endl << "2. Dodać przynajmniej 5 recenzji." << endl;
        cout << "Dzięki niej możesz wypożyczać filmy na dłuższy okres: 20 dni!" << endl;

        if ((borrowedFilmsNumber + borrowedSeriesNumber) >= 20 && reviewsNumber >= 5) {
            loyaltyCard = true;
            cout << "Karta założona!" << endl;
        } else {
            cout << "Niestety nie spełniasz warunków koniecznych do założenia karty." << endl;
        }
    }
}

void User::create() {
    string newLogin, newPassword[2];
    bool samePasswords = true;
    bool foundUser = true;

    while (foundUser) {
        try {
            cout << "Wpisz login: ";
            cin >> newLogin;
            foundUser = findUser(newLogin);

            if (foundUser)
                throw "Ta nazwa jest już zajęta!";
            else
                foundUser = false;
        }
        catch(const char* error) {
            cout << error << endl;
        }
    }

    while (samePasswords) {
        try {
            cout << "Wpisz hasło: ";
            cin >> newPassword[0];
            cout << "Wpisz ponownie hasło: ";
            cin >> newPassword[1];
            if (newPassword[0] != newPassword[1])
                throw "Hasła nie są takie same!";
            else
                samePasswords = false;
        }
        catch (const char *error) {
            cout << error << endl;
        }
    }
    login = newLogin;
    password = newPassword[0];
}

void User::registerNewUser() {

    ofstream writeFile("../Users.csv", ios::app);
    if (writeFile.good()) {
        writeFile << login << ',' << password << "\n";
    } else {
        cout << "Błąd podczas otwierania pliku Users.txt!" << endl;
        exit(1);
    }
    writeFile.close();
}

void User::saveToFile() { //TODO
    cout << "Zapisałem dane użytkownika do pliku!" << endl;
}

void User::loginToRental(const char *eLogin, const char *ePassword) {

    ifstream readFile("../Users.csv", ios::in);
    string line;
    vector<string> row;

    if (readFile.good()) {
        while (getline(readFile, line)) {
            row = breakTheLine(line);
            if (row[0] == eLogin && row[1] == ePassword) {
                login = eLogin;
                password = ePassword;
                cout << "Logowanie zakończone sukcesem!" << endl;
                break;
            }
        }
        readFile.close();
    }
    else {
        cout << "Błąd podczas otwierania pliku Users.txt!" << endl;
        exit(1);
    }

    if (login != eLogin && password != ePassword) {
        cout << "Wprowadzono błędny login lub hasło!\n";
        exit(1);
    }

}

bool User::isFilmBorrowed(const string &title) {
    for (auto& video : borrowedFilms) {
        if (video->getName() == title)
            return true;
    }
    return false;
}

bool User::wasFilmBorrowed(const string &title) {
    for (auto& video : borrowedFilmsHistory) {
        if (video->getName() == title)
            return true;
    }
    return false;
}

bool User::isSeriesBorrowed(const string &title) {
    for (auto& video : borrowedSeries) {
        if (video->getName() == title)
            return true;
    }
    return false;
}

bool User::wasSeriesBorrowed(const string &title) {
    for (auto& video : borrowedSeriesHistory) {
        if (video->getName() == title)
            return true;
    }
    return false;
}

void User::incrementReviewsNumber() {
    reviewsNumber++;
}

void User::setLoyaltyCard(bool flag) {
    loyaltyCard = flag;
}

void User::addFilmToHistory(Film* film) {
    borrowedFilmsHistory.push_back(film);
    borrowedFilmsNumber++;
}

void User::addSeriesToHistory(Series* series) {
    borrowedSeriesHistory.push_back(series);
    borrowedSeriesNumber++;
}

void User::setReviewsNumber(unsigned int number) {
    reviewsNumber = number;
}

