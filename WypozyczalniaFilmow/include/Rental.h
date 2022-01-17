// Główny plik programu - zawiera wszystkie funkcje dotyczące uruchomienia go oraz funkcjonalności z nim związane

#ifndef WYPOZYCZALNIAFILMOW_RENTAL_H
#define WYPOZYCZALNIAFILMOW_RENTAL_H

#include "Recording.h"
#include "User.h"
#include <vector>

class Rental {
public:
    // Konstruktor
    Rental();
    // Destruktor
    ~Rental();

    // Wyświetlenie wszystkich filmów i seriali
    void printAll();
    // Wyświetlenie wszystkich filmów
    void printFilmsTitles();
    // Wyświetlenie wszystkich seriali
    void printSeriesTitles();
    // Wyświetlenie super specjalnego filmu
    void printSuperSpecialFilm();
    // Załadowanie zawartości wypożyczalni z pliku
    void loadContent();
    // Załadowanie informacji z pliku użytkownika
    void loadUserData(User& user);
    // Rozpoczęcie działania programu
    void run(int argc, char* argv[]);
    // Metoda pozwalająca na wypożyczenie nagrania
    void borrowRecording(User& user);
    // Metoda pozwalająca na oddanie nagrania
    void giveBackRecording(User& user);
    // Metoda do aplikowania o kartę stałego klienta
    void applyForLoyaltyCard(User& user);
    // Wyszukiwanie filmu po nazwie
    Film* searchFilmByTitle(const std::string& title);
    // Wyszukiwanie serialu po nazwie
    Series* searchSeriesByTitle(const std::string& title);

    // Metoda dodająca nową recenzję
    void addNewReview(User& user);
    // Metoda zapisująca nową recenzję do pliku
    void saveNewReview(const Review& newReview, const std::string& recordingName, bool type);
    // Wypisanie informacji o użytkowniku
    void printUserInfo(const User& user) const;
    // Wypisanie opcji menu
    void printMenuOptions() const;
    // Wypisanie filmów i seriali użytkownika
    void printUserFilms(const User& user) const;
    // Wypisanie historii filmów i seriali użytkownika
    void printUserFilmsHistory(const User& user) const;
    // Metoda, która zamraża działanie programu do czasu wciśnięcia klawisza ENTER
    void freezeTheScreen();

private:
    bool isOpen = false;
    std::vector<Film> films;
    std::vector<Series> series;
    Recording* superSpecialFilm = nullptr;
};

#endif //WYPOZYCZALNIAFILMOW_RENTAL_H
