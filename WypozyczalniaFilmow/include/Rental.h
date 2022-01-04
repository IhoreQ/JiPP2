#ifndef WYPOZYCZALNIAFILMOW_RENTAL_H
#define WYPOZYCZALNIAFILMOW_RENTAL_H

#include "Film.h"
#include "User.h"
#include "Series.h"
#include "Review.h"
#include <vector>

class Rental {
public:
    Rental();
    ~Rental();
    void printAll();
    void printFilmsTitles();
    void printSeriesTitles();
    void loadContent();
    void run(int argc, char* argv[]);
    void borrowRecording(User& user);
    void giveBackRecording(User& user);
    Film* searchFilmByTitle(const std::string& title);
    Series* searchSeriesByTitle(const std::string& title);

    void printMenuOptions() const;

private:
    bool isOpen = false;
    std::vector<Film> films;
    std::vector<Series> series;
};

#endif //WYPOZYCZALNIAFILMOW_RENTAL_H
