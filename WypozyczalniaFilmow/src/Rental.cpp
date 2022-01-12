#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../include/Rental.h"
#include "../include/helpfulFunctions.h"

using namespace std;

Rental::Rental() = default;

Rental::~Rental() {
    cout << "Zapraszamy ponownie!" << endl;
}

void Rental::run(int argc, char* argv[]) {

    int option;
    User user;
    loadContent();

    /* ------------------------------- REJESTRACJA ORAZ LOGOWANIE ------------------------------- */

    // Nie podano argumentów początkowych - rejestracja lub wyjście
    if (argc == 1) {
        cout << "Witamy w wypożyczalni filmów! Widocznie nie posiadasz konta, jeśli chcesz je założyć, wpisz 1 i wciśnij ENTER.\n"
                "Jeśli jednak posiadasz konto wpisz 0, a następnie włącz program z dwoma parametrami - login i hasło.\n";
        cout << "Opcja: ";

        checkInput(option, 0, 1);

        if (option == 0)
            exit(1);
        else {
            user.create();
            user.registerNewUser();
        }
    }
    // Podano login i hasło jako argumenty
    else if (argc == 3) {
        user.loginToRental(argv[1], argv[2]);
        loadUserData(user);
    }
    // Podano błędną ilość argumentów
    else {
        cout << "Podano błędną ilość argumentów!\n"
                "Włącz program ponownie w jeden z podanych sposobów:\n"
                "1. WypozyczalniaFilmow (w celu rejestracji)\n"
                "2. WypozyczalniaFilmow [login] [haslo] (w celu zalogowania się do systemu)\n";
        exit(1);
    }

    /* ------------------------------- PĘTLA GŁÓWNA PROGRAMU ------------------------------- */

    isOpen = true;

    while (isOpen) {
        system("clear");
        printUserInfo(user);
        cout << "------------------------------------------\n";
        printMenuOptions();
        cout << "Opcja: ";
        checkInput(option, 1, 8);

        switch (option) {
            case 1:
                system("clear");
                printAll();
                freezeTheScreen();
                break;
            case 2:
                system("clear");
                borrowRecording(user);
                freezeTheScreen();
                break;
            case 3:
                system("clear");
                giveBackRecording(user);
                freezeTheScreen();
                break;
            case 4:
                system("clear");
                addNewReview(user);
                freezeTheScreen();
                break;
            case 5:
                system("clear");
                user.printBorrowedFilms();
                cout << "\n";
                user.printBorrowedSeries();
                freezeTheScreen();
                break;
            case 6:
                system("clear");
                user.printBorrowedFilmsHistory();
                cout << "\n";
                user.printBorrowedSeriesHistory();
                freezeTheScreen();
                break;
            case 7:
                system("clear");
                user.applyForLoyaltyCard();
                freezeTheScreen();
                break;
            case 8:
                cout << "Dziękujemy za skorzystanie z naszej wypożyczalni! Do zobaczenia :)\n";
                isOpen = false;
            default:
                break;
        }
    }
}

void Rental::printUserInfo(const User& user) const {
    cout << "Login: " << user.getLogin() << endl;
    cout << "Liczba wszystkich wypożyczonych filmów: " << user.getBorrowedFilmsNumber() << endl;
    cout << "Liczba wszystkich wypożyczonych seriali: " << user.getBorrowedSeriesNumber() << endl;
    cout << "Liczba dodanych recenzji: " << user.getReviewsNumber() << endl;
    if (user.getLoyaltyCardInfo())
        cout << "Karta stałego klienta: W posiadaniu" << endl;
    else
        cout << "Karta stałego klienta: Brak" << endl;
}

void Rental::printMenuOptions() const {

    const string menuOps[8] {
        "1 - Wyświetl dostępne filmy i seriale",
        "2 - Wypożycz film lub serial",
        "3 - Oddaj film lub serial",
        "4 - Dodaj recenzję",
        "5 - Wyświetl moje filmy i seriale",
        "6 - Wyświetl historię moich filmów i seriali",
        "7 - Załóż kartę stałego klienta",
        "8 - Zakończ program"
    };

    for (auto& element : menuOps)
        cout << element << endl;

}

void Rental::printFilmsTitles() { // TODO
    string dashes(54, '-');
    cout << "Lp.\tNazwa\tGatunek\tData publikacji" << endl;
    cout << dashes << endl;
    int i = 1;
    for (auto& video : films)
        cout << i++ << ".\t" << video << endl;
}

void Rental::printSeriesTitles() { // TODO
    string dashes(77, '-');
    cout << "Lp.\tNazwa\tGatunek\tData publikacji\tLiczba odcinków\tLiczba sezonów" << endl;
    cout << dashes << endl;
    int i = 1;
    for (auto& video : series)
        cout << i++ << ".\t" << video << endl;
}

void Rental::loadContent() {
    ifstream contentFile("../rentalContent.csv");
    Film loadedFilm;
    Series loadedSeries;
    Review loadedReview;
    string line;
    vector<string> row;

    if (!contentFile.good()) {
        cout << "Błąd podczas otwierania pliku rentalContent.csv!\n";
        exit(1);
    }

    if (contentFile.is_open()) {
        while(getline(contentFile, line)) {
            row = breakTheLine(line);

            if (row[0] == "Film") {
                loadedFilm.setLoadedValues(row[1], row[2], stoi(row[3]), row[4]);
                films.push_back(loadedFilm);
            }
            else if (row[0] == "Serial") {
                loadedSeries.setLoadedValues(row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]));
                series.push_back(loadedSeries);
            }
        }
    }

    contentFile.close();

    ifstream reviewFile("../filmsReviews.csv");

    if (!reviewFile.good()) {
        cout << "Błąd podczas otwierania pliku reviews.csv!\n";
    }

    if (reviewFile.is_open()) {
        while (getline(reviewFile, line)) {
            row = breakTheLine(line);
            if (row[0] == "Film") {
                loadedReview.setLoadedValues(row[2], row[3], stoi(row[4]));
                for (auto& video : films) {
                    if (video.getName() == row[1]) {
                        video.insertNewReview(loadedReview);
                        break;
                    }
                }
            }
            else if (row[0] == "Serial") {
                loadedReview.setLoadedValues(row[2], row[3], stoi(row[4]));
                for (auto& video : series) {
                    if (video.getName() == row[1])
                        video.insertNewReview(loadedReview);
                }
            }
        }
    }
    reviewFile.close();
    cout << "Wczytywanie zakończone!\n";
}

void Rental::printAll() {
    cout << "Dostępne filmy:" << endl;
    printFilmsTitles();
    cout << "Dostępne seriale:" << endl;
    printSeriesTitles();
}

void Rental::borrowRecording(User& user) {

    int option;
    string name;

    cout << "Co chcesz wypożyczyć?\n1. Film\n2. Serial\n3. Rezygnuję" << endl << "Opcja: ";
    checkInput(option, 1, 3);

    if (option == 1) {

        printFilmsTitles();
        cout << "Podaj nazwę filmu, który chcesz wypożyczyć: ";
        getline(cin>>ws, name);
        Film* searchingFilm = searchFilmByTitle(name);

        if (searchingFilm == nullptr)
            cout << "Niestety, takiego filmu nie ma nawet w naszej wypożyczalni." << endl;
        else {
            cout << "Czy chcesz zobaczyć opis, ocenę i recenzje filmu? (1 - tak, 0 - nie)" << endl;
            cout << "Opcja: ";
            checkInput(option, 0, 1);
            if (option) {
                cout << searchingFilm->getName() << ": " << endl;
                cout << "Opis: " << searchingFilm->getDescription() << endl;
                cout << "Średnia ocena: " << searchingFilm->getAverageScore() << endl;
                cout << "Recenzje:" << endl;
                cout << "-------------------------------------" << endl;
                searchingFilm->printReviews();

                cout << "Czy chcesz wypożyczyć ten film? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isFilmBorrowed(searchingFilm->getName()))
                        cout << "Już posiadasz ten film!" << endl;
                    else
                        user.borrowFilm(searchingFilm);
                }
            }
            else {
                cout << "Czy chcesz zobaczyć wypożyczyć ten film? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isFilmBorrowed(searchingFilm->getName()))
                        cout << "Już posiadasz ten film!" << endl;
                    else
                        user.borrowFilm(searchingFilm);
                }
            }
        }
    }
    else if (option == 2) {
        printSeriesTitles();
        cout << "Podaj nazwę serialu, który chcesz wypożyczyć: ";
        getline(cin>>ws, name);
        Series* searchingSeries = searchSeriesByTitle(name);

        if (searchingSeries == nullptr)
            cout << "Niestety, takiego serialu nie ma nawet w naszej wypożyczalni." << endl;
        else {
            cout << "Czy chcesz zobaczyć opis, ocenę i recenzje serialu? (1 - tak, 0 - nie)" << endl;
            cout << "Opcja: ";
            checkInput(option, 0, 1);
            if (option) {
                cout << searchingSeries->getName() << ": " << endl;
                cout << "Opis: " << searchingSeries->getDescription() << endl;
                cout << "Średnia ocena: " << searchingSeries->getAverageScore() << endl;
                cout << "Recenzje:" << endl;
                cout << "-------------------------------------" << endl;
                searchingSeries->printReviews();

                cout << "Czy chcesz wypożyczyć ten serial? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isSeriesBorrowed(searchingSeries->getName()))
                        cout << "Już posiadasz ten serial!" << endl;
                    else
                        user.borrowSeries(searchingSeries);
                }
            }
            else {
                cout << "Czy chcesz zobaczyć wypożyczyć ten serial? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isSeriesBorrowed(searchingSeries->getName()))
                        cout << "Już posiadasz ten serial!" << endl;
                    else
                        user.borrowSeries(searchingSeries);
                }
            }
        }
    }
}

void Rental::giveBackRecording(User &user) {

    int option;
    string name;

    cout << "Co chcesz oddać?\n1. Film\n2. Serial\n3. Rezygnuję" << endl << "Opcja: ";
    checkInput(option, 1, 3);

    system("clear");
    if (option == 1) {

        cout << "Twoje filmy:" << endl;
        user.printBorrowedFilms();

        cout << "Podaj nazwę filmu, który chcesz oddać: ";
        getline(cin>>ws, name);
        Film* searchingFilm = searchFilmByTitle(name);

        if (searchingFilm == nullptr)
            cout << "Niestety, takiego filmu nie ma nawet w naszej wypożyczalni." << endl;
        else {
            if (user.isFilmBorrowed(searchingFilm->getName())) {
                cout << "Czy na pewno chcesz oddać ten film? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                checkInput(option, 0, 1);
                if (option)
                    user.giveBackFilm(searchingFilm->getName());
            }
            else
                cout << "Nie posiadasz takiego filmu!\n";
        }
    }
    else if (option == 2) {

        cout << "Twoje seriale: " << endl;
        user.printBorrowedSeries();

        cout << "Podaj nazwę serialu, który chcesz oddać: ";
        getline(cin>>ws, name);
        Series* searchingSeries = searchSeriesByTitle(name);

        if (searchingSeries == nullptr)
            cout << "Niestety, takiego serialu nie ma nawet w naszej wypożyczalni." << endl;
        else {
            if (user.isSeriesBorrowed(searchingSeries->getName())) {
                cout << "Czy na pewno chcesz oddać ten serial? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                checkInput(option, 0, 1);
                if (option)
                    user.giveBackSeries(searchingSeries->getName());
            }
            else
                cout << "Nie posiadasz takiego serialu!\n";
        }
    }
}

Film* Rental::searchFilmByTitle(const string& title) {
    for (auto& video : films) {
        if (video.getName() == title) {
            return &video;
        }
    }
    return nullptr;
}

Series* Rental::searchSeriesByTitle(const string& title) {
    for (auto& video : series) {
        if (video.getName() == title) {
            return &video;
        }
    }
    return nullptr;
}

void Rental::freezeTheScreen() {
    cout << "Aby kontynuować wciśnij klawisz ENTER." << endl;
    cin.get();
}

void Rental::addNewReview(User& user) {

    Review newReview;
    int newScore;
    string newContent, name;
    int option;

    cout << "Co chcesz ocenić?\n1. Film\n2. Serial\n3. Rezygnuję" << endl << "Opcja: ";
    checkInput(option, 1, 3);

    system("clear");
    if (option == 1) {

        cout << "Historia twoich filmów:" << endl;
        user.printBorrowedFilmsHistory();

        cout << "Podaj nazwę filmu, do którego chcesz dodać recenzję: ";
        getline(cin >> ws, name);
        Film *searchingFilm = searchFilmByTitle(name);

        if (searchingFilm == nullptr)
            cout << "Niestety, nie posiadasz takiego filmu w swojej historii." << endl;
        else {
            if (user.wasFilmBorrowed(searchingFilm->getName())) {
                cout << "Podaj ocenę jaką chcesz wystawić filmowi (1-10): ";
                checkInput(newScore, 1, 10);

                cout << "Wpisz swoją recenzję: ";
                getline(cin >> ws, newContent);

                newReview.setLoadedValues(user.getLogin(), newContent, newScore);
                searchingFilm->insertNewReview(newReview);
                user.incrementReviewsNumber();

                saveNewReview(newReview, searchingFilm->getName(), true);
            }
            else
                cout << "Nie miałeś takiego filmu, więc nie możesz dodać do niego recenzji!\n";
        }
    } else if (option == 2) {
        cout << "Historia twoich seriali:" << endl;
        user.printBorrowedSeriesHistory();

        cout << "Podaj nazwę serialu, do którego chcesz dodać recenzję: ";
        getline(cin >> ws, name);
        Series *searchingSeries = searchSeriesByTitle(name);

        if (searchingSeries == nullptr)
            cout << "Niestety, takiego serialu nie ma nawet w naszej wypożyczalni.." << endl;
        else {
            if (user.wasSeriesBorrowed(searchingSeries->getName())) {
                cout << "Podaj ocenę jaką chcesz wystawić serialowi (1-10): ";
                checkInput(newScore, 1, 10);

                cout << "Wpisz swoją recenzję: ";
                getline(cin >> ws, newContent);

                newReview.setLoadedValues(user.getLogin(), newContent, newScore);
                searchingSeries->insertNewReview(newReview);
                user.incrementReviewsNumber();

                saveNewReview(newReview, searchingSeries->getName(), false);
            }
            else
                cout << "Nie miałeś takiego serialu, więc nie możesz dodać do niego recenzji!\n";
        }
    }
}

void Rental::saveNewReview(const Review& newReview, const string& recordingName, bool type) {

    ofstream reviewsFile("../filmsReviews.csv", ios::app);

    if (!reviewsFile.good()) {
        cout << "Wystąpił błąd podczas próby otwarcia pliku filmsReviews.csv\n";
        exit(1);
    }
    if (reviewsFile.is_open()) {
        if (type) {
            reviewsFile << "Film" << ',' << recordingName << ',' << newReview.getWhoAdded() << ',' << '"' << newReview.getContent() << '"' << ',' << newReview.getScore() << "\n";
        }
        else {
            reviewsFile << "Serial" << ',' << recordingName << ',' << newReview.getWhoAdded() << ',' << '"' << newReview.getContent() << '"' << ',' << newReview.getScore() << "\n";
        }
    }

    reviewsFile.close();
}

void Rental::loadUserData(User& user) {

    string userPath = "../Users/" + user.getLogin() + ".csv";
    string line;
    vector<string> row;
    bool first = true, second = false;
    ifstream userFile(userPath.c_str());
    Film* userFilm = nullptr;
    Series* userSeries = nullptr;

    if (!userFile.good()) {
        cout << "Błąd podczas otwierania pliku " << user.getLogin() << ".csv!\n";
        exit(1);
    }

    if (userFile.is_open()) {
        while (getline(userFile, line)) {
            row = breakTheLine(line);
            if (first) {
                if (row[3] == "tak") {
                    user.setLoyaltyCard(true);
                    first = false;
                }
                else if (row[3] == "nie") {
                    user.setLoyaltyCard(false);
                    first = false;
                }
                if (second) {
                    user.setReviewsNumber(stoi(row[4]));
                }
                second = true;
            }

            if (row[0] == "Film") {
                userFilm = searchFilmByTitle(row[1]);
                if (row[2] == "tak") {
                    user.borrowFilm(userFilm);
                }
                else if (row[2] == "nie") {
                    user.addFilmToHistory(userFilm);
                }
            }
            else if (row[0] == "Serial") {
                userSeries = searchSeriesByTitle(row[1]);
                if (row[2] == "tak") {
                    user.borrowSeries(userSeries);
                }
                else if (row[2] == "nie") {
                    user.addSeriesToHistory(userSeries);
                }
            }
        }
        userFile.close();
    }
}
