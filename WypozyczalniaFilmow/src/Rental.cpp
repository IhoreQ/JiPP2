#include <iostream>
#include <fstream>
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
        // Wczytanie danych dla użytkownika z pliku TODO
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

    loadContent();

    while (isOpen) {
        printMenuOptions();
        checkInput(option, 1, 8);

        switch (option) {
            case 1:
                system("clear");
                printAll();
                system("pause");
                break;
            case 2:
                system("clear");
                borrowRecording(user);
                system("pause");
                break;
            case 3:
                system("clear");
                giveBackRecording(user);
                break;
            case 4:

                break;
            case 5:
                // TODO print all
                system("clear");
                user.printBorrowedFilms();
                user.printBorrowedSeries();
                system("pause");
                break;
            case 6:
                // TODO print all
                system("clear");
                user.printBorrowedFilmsHistory();
                user.printBorrowedSeriesHistory();
                system("pause");
                break;
            case 7:
                system("clear");
                user.applyForLoyaltyCard();
                system("pause");
                break;
            case 8:
                cout << "Dziękujemy za skorzystanie z naszej wypożyczalni! Do zobaczenia :)\n";
                isOpen = false;
            default:
                break;
        }
    }
}

void Rental::printMenuOptions() const {

    const string menuOps[8] {
        "1 - Wyświetl dostępne filmy i seriale",
        "2 - Wypożycz film",
        "3 - Oddaj film",
        "4 - Dodaj recenzję",
        "5 - Wyświetl moje filmy i seriale",
        "6 - Wyświetl historię moich filmów i seriali",
        "7 - Załóż kartę stałego klienta",
        "8 - Zakończ program"
    };
}

void Rental::printFilmsTitles() {
    string dashes(54, '-');
    cout << "Lp.\tNazwa\tGatunek\tData publikacji" << endl;
    cout << dashes;
    int i = 1;
    for (auto& video : films) {
        if (!video.isBorrowing())
            cout << i << ".\t" << video << endl;
    }
}

void Rental::printSeriesTitles() {
    string dashes(77, '-');
    cout << "Lp.\tNazwa\tGatunek\tData publikacji\tLiczba odcinków" << endl;
    cout << dashes;
    int i = 1;
    for (auto& video : series) {
        if (!video.isBorrowing())
            cout << i << ".\t" << video << endl;
    }
}

void Rental::loadContent() {
    // TODO
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

    cout << "Co chcesz wypożyczyć?\n 1. Film\n2. Serial\n3. Rezygnuję" << endl << "Opcja: ";
    cin >> option;
    checkInput(option, 1, 3);

    if (option == 1) {
        cout << "Podaj nazwę filmu, który chcesz wypożyczyć: ";
        cin >> name;
        Film* searchingFilm = searchFilmByTitle(name);

        if (searchingFilm == nullptr)
            cout << "Niestety, nie mamy takiego filmu." << endl;
        else {
            cout << "Czy chcesz zobaczyć opis, ocenę i recenzje filmu? (1 - tak, 0 - nie)" << endl;
            cout << "Opcja: ";
            cin >> option;
            checkInput(option, 0, 1);
            if (option) {
                cout << searchingFilm->getName() << ": " << endl;
                cout << "Opis: " << searchingFilm->getDescription() << endl;
                cout << "Średnia ocena: " << searchingFilm->getAverageScore() << endl;
                cout << "Recenzje:" << endl;
                cout << "-------------------------------------" << endl;
                searchingFilm->printReviews();

                cout << "Czy chcesz zobaczyć wypożyczyć ten film? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                cin >> option;
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isFilmBorrowed(searchingFilm->getName()))
                        cout << "Już posiadasz ten film!" << endl;
                    else {
                        user.borrowFilm(searchingFilm);
                        searchingFilm->setBorrowing(true);
                    }
                }
            }
            else {
                cout << "Czy chcesz zobaczyć wypożyczyć ten film? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                cin >> option;
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isFilmBorrowed(searchingFilm->getName()))
                        cout << "Już posiadasz ten film!" << endl;
                    else {
                        user.borrowFilm(searchingFilm);
                        searchingFilm->setBorrowing(true);
                    }
                }
            }
        }
    }
    else if (option == 2) {
        cout << "Podaj nazwę serialu, który chcesz wypożyczyć: ";
        cin >> name;
        Series* searchingSeries = searchSeriesByTitle(name);

        if (searchingSeries == nullptr)
            cout << "Niestety, nie mamy takiego serialu." << endl;
        else {
            cout << "Czy chcesz zobaczyć opis, ocenę i recenzje serialu? (1 - tak, 0 - nie)" << endl;
            cout << "Opcja: ";
            cin >> option;
            checkInput(option, 0, 1);
            if (option) {
                cout << searchingSeries->getName() << ": " << endl;
                cout << "Opis: " << searchingSeries->getDescription() << endl;
                cout << "Średnia ocena: " << searchingSeries->getAverageScore() << endl;
                cout << "Recenzje:" << endl;
                cout << "-------------------------------------" << endl;
                searchingSeries->printReviews();

                cout << "Czy chcesz zobaczyć wypożyczyć ten serial? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                cin >> option;
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isSeriesBorrowed(searchingSeries->getName()))
                        cout << "Już posiadasz ten serial!" << endl;
                    else {
                        user.borrowSeries(searchingSeries);
                        searchingSeries->setBorrowing(true);
                    }
                }
            }
            else {
                cout << "Czy chcesz zobaczyć wypożyczyć ten serial? (1 - tak, 0 - nie)" << endl;
                cout << "Opcja: ";
                cin >> option;
                checkInput(option, 0, 1);
                if (option) {
                    if (user.isSeriesBorrowed(searchingSeries->getName()))
                        cout << "Już posiadasz ten serial!" << endl;
                    else {
                        user.borrowSeries(searchingSeries);
                        searchingSeries->setBorrowing(true);
                    }
                }
            }
        }
    }
}

void Rental::giveBackRecording(User &user) {

    int option;
    string name;

    cout << "Co chcesz oddać?\n 1. Film\n2. Serial\n3. Rezygnuję" << endl << "Opcja: ";
    cin >> option;
    checkInput(option, 1, 3);

    system("clear");
    if (option == 1) {

        cout << "Twoje filmy:" << endl;
        user.printBorrowedFilms();

        cout << "Podaj nazwę filmu, który chcesz oddać: ";
        cin >> name;
        Film* searchingFilm = searchFilmByTitle(name);

        if (searchingFilm == nullptr)
            cout << "Niestety, nie posiadasz takiego filmu." << endl;
        else {
            cout << "Czy na pewno chcesz oddać ten film? (1 - tak, 0 - nie)" << endl;
            cout << "Opcja: ";
            cin >> option;
            checkInput(option, 0, 1);
            if (option) {
                user.giveBackFilm(searchingFilm->getName());
                searchingFilm->setBorrowing(false);
            }
        }
    }
    else if (option == 2) {

        cout << "Twoje seriale: " << endl;
        user.printBorrowedSeries();

        cout << "Podaj nazwę serialu, który chcesz oddać: ";
        cin >> name;
        Series* searchingSeries = searchSeriesByTitle(name);

        if (searchingSeries == nullptr)
            cout << "Niestety, nie posiadasz takiego serialu." << endl;
        else {
            cout << "Czy na pewno chcesz oddać ten serial? (1 - tak, 0 - nie)" << endl;
            cout << "Opcja: ";
            cin >> option;
            checkInput(option, 0, 1);
            if (option) {
                user.giveBackSeries(searchingSeries->getName());
                searchingSeries->setBorrowing(false);
            }
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

