#ifndef WYPOZYCZALNIAFILMOW_RENTAL_H
#define WYPOZYCZALNIAFILMOW_RENTAL_H

#include "Recording.h"
#include "User.h"
#include <vector>

class Rental {
public:
    Rental();
    ~Rental();

    void printAll();
    void printFilmsTitles();
    void printSeriesTitles();
    void loadContent();
    void loadUserData(User& user);
    void run(int argc, char* argv[]);
    void borrowRecording(User& user);
    void giveBackRecording(User& user);
    Film* searchFilmByTitle(const std::string& title);
    Series* searchSeriesByTitle(const std::string& title);

    void addNewReview(User& user);
    void saveNewReview(const Review& newReview, const std::string& recordingName, bool type);
    void printUserInfo(const User& user) const;
    void printMenuOptions() const;

    void freezeTheScreen();

private:
    bool isOpen = false;
    std::vector<Film> films;
    std::vector<Series> series;
};

#endif //WYPOZYCZALNIAFILMOW_RENTAL_H
