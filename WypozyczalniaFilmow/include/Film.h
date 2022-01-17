#ifndef WYPOZYCZALNIAFILMOW_FILM_H
#define WYPOZYCZALNIAFILMOW_FILM_H

#include "Recording.h"

class Film : public Recording {
    // Przeciążenie operatora << do wyświetlania informacji o filmie
    friend std::ostream& operator<<(std::ostream& lhs, const Film& rhs);
public:
    // Konstruktor domyślny
    Film();
    // Konstruktor z argumentami
    Film(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear, const std::string& newFilmDescription);


    // Pobieranie nazwy serialu
    std::string getName() override;
    // Pobieranie liczby recenzji
    unsigned getReviewCount() override;
    // Pobieranie gatunku serialu
    std::string getGenre() override;
    // Pobieranie średniej oceny serialu
    double getAverageScore() override;
    // Pobieranie roku publikacji serialu
    unsigned getPublicationYear() override;
    // Pobieranie opisu serialu
    std::string getDescription() override;
    // Wypisanie opisu serialu
    void printDescription() const override;
    // Wypisanie wszystkich recenzji
    void printReviews() override;

    // Przeciążenie operatora == (czy nazwy dwóch seriali są takie same)
    bool operator==(const Film& rhs) const;

    // Metoda dodająca do kontenera recenzji obiekt newReview
    void insertNewReview(const Review& newReview) override;
    // Metoda ustalająca podstawowe dane o filmie
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription) override;
    // Metoda dziedziczona po klasie abstrakcyjnej - w tej klasie nieużywana
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription, unsigned newEpisodesNumber, unsigned newSeasonsNumber) override;

private:
    std::string filmDescription;
};

#endif //WYPOZYCZALNIAFILMOW_FILM_H
