#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
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
    saveToFile();
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

void User::printBorrowedFilms() const {

    if (borrowedFilms.empty())
        cout << "Brak wypożyczonych filmów!" << endl;
    else {
        cout << "Wypożyczone filmy:" << endl;
        string dashes(82, '-');
        cout << "Lp." << setw(39) << "Nazwa" << setw(20) << "Gatunek" << setw(20) << "Data publikacji" << endl;
        cout << dashes << endl;
        int i = 1;
        for (auto& video : borrowedFilms) {
            if (i < 10)
                cout << i++ << "." << setw(40) << *video << endl;
            else if (i < 100)
                cout << i++ << "." << setw(39) << *video << endl;
            else
                cout << i++ << "." << setw(38) << *video << endl;
        }
    }
}

void User::printBorrowedFilmsHistory() const {

    if (borrowedFilmsHistory.empty())
        cout << "Brak wypożyczonych filmów w historii!" << endl;
    else {
        cout << "Historia wypożyczonych filmów:" << endl;
        string dashes(82, '-');
        cout << "Lp." << setw(39) << "Nazwa" << setw(20) << "Gatunek" << setw(20) << "Data publikacji" << endl;
        cout << dashes << endl;
        int i = 1;
        for (auto& video : borrowedFilmsHistory) {
            if (i < 10)
                cout << i++ << "." << setw(40) << *video << endl;
            else if (i < 100)
                cout << i++ << "." << setw(39) << *video << endl;
            else
                cout << i++ << "." << setw(38) << *video << endl;
        }
    }
}
void User::printBorrowedSeries() const {

    if (borrowedSeries.empty())
        cout << "Brak wypożyczonych seriali!" << endl;
    else {
        cout << "Wypożyczone seriale:" << endl;
        string dashes(122, '-');
        cout << "Lp." << setw(39) << "Nazwa" << setw(20) << "Gatunek" << setw(20) << "Data publikacji" << setw(21) << "Liczba odcinków" << setw(21) << "Liczba sezonów" << endl;
        cout << dashes << endl;

        int i = 1;
        for (auto& video : borrowedSeries)
            if (i < 10)
                cout << i++ << "." << setw(40) << *video << endl;
            else if (i < 100)
                cout << i++ << "." << setw(39) << *video << endl;
            else
                cout << i++ << "." << setw(38) << *video << endl;
    }
}

void User::printBorrowedSeriesHistory() const {

    if (borrowedSeriesHistory.empty())
        cout << "Brak wypożyczonych seriali w historii!" << endl;
    else {
        cout << "Historia wypożyczonych seriali:" << endl;
        string dashes(122, '-');
        cout << "Lp." << setw(39) << "Nazwa" << setw(20) << "Gatunek" << setw(20) << "Data publikacji" << setw(21) << "Liczba odcinków" << setw(21) << "Liczba sezonów" << endl;
        cout << dashes << endl;

        int i = 1;
        for (auto& video : borrowedSeriesHistory)
            if (i < 10)
                cout << i++ << "." << setw(40) << *video << endl;
            else if (i < 100)
                cout << i++ << "." << setw(39) << *video << endl;
            else
                cout << i++ << "." << setw(38) << *video << endl;
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

void User::saveToFile() {

    string userPath = "../Users/" + login + ".csv";
    string firstLine = "Typ,Nazwa,Aktualnie wypożyczony,Karta stałego klienta,Ilość recenzji";
    vector<string> row;
    row = breakTheLine(firstLine);
    bool first = true;

    ofstream userFile(userPath.c_str());

    if (!userFile.good()) {
        cout << "Błąd podczas otwierania pliku do zapisu!\n";
    }

    if (userFile.is_open()) {
        for (auto& element : row)
            userFile << element << ',';
        userFile << "\n";

        for (auto& element : borrowedFilmsHistory) {
            userFile << "Film," << element->getName() << ',';
            if (isFilmBorrowed(element->getName()))
                userFile << "tak,";
            else
                userFile << "nie,";

            if (first) {
                if (loyaltyCard)
                    userFile << "tak," << reviewsNumber << ',' << borrowedFilmsNumber << ',' << borrowedSeriesNumber;
                else
                    userFile << "nie," << reviewsNumber << ',' << borrowedFilmsNumber << ',' << borrowedSeriesNumber;
                first = false;
            }
            userFile << "\n";
        }

        for (auto& element : borrowedSeriesHistory) {
            userFile << "Serial," << element->getName() << ',';
            if (isSeriesBorrowed(element->getName()))
                userFile << "tak\n";
            else
                userFile << "nie\n";
        }
        userFile.close();
    }

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

void User::loadFilmToHistory(Film* film) {
    borrowedFilmsHistory.push_back(film);
}

void User::loadSeriesToHistory(Series* series) {
    borrowedSeriesHistory.push_back(series);
}

void User::setReviewsNumber(unsigned int number) {
    reviewsNumber = number;
}

bool User::isFilmHistoryVectorEmpty() {
    if (borrowedFilmsHistory.empty())
        return true;
    return false;
}

bool User::isSeriesHistoryVectorEmpty() {
    if (borrowedSeriesHistory.empty())
        return true;
    return false;
}

bool User::checkFilmsAndSeriesEmpty() const {

    if (borrowedFilms.empty() && borrowedSeries.empty())
        return true;
    return false;
}

bool User::checkFilmsAndSeriesHistoryEmpty() const {
    if (borrowedFilmsHistory.empty() && borrowedSeriesHistory.empty())
        return true;
    return false;
}

void User::setBorrowedFilmsNumber(unsigned int number) {
    borrowedFilmsNumber = number;
}

void User::setBorrowedSeriesNumber(unsigned int number) {
    borrowedSeriesNumber = number;
}

void User::loadFilmToBorrowed(Film *film) {
    borrowedFilms.push_back(film);
    if (!(wasFilmBorrowed(film->getName())))
        borrowedFilmsHistory.push_back(film);
}

void User::loadSeriesToBorrowed(Series *series) {
    borrowedSeries.push_back(series);
    if (!(wasFilmBorrowed(series->getName())))
        borrowedSeriesHistory.push_back(series);
}

