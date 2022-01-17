// Plik serialu - zawiera wszystkie funkcjonalności pobierania danych o serialu, ustalania ich i wyświetlania

#ifndef WYPOZYCZALNIAFILMOW_SERIES_H
#define WYPOZYCZALNIAFILMOW_SERIES_H

#include "Recording.h"

class Series : public Recording {
    // Przeciążenie operatora << do wyświetlania informacji o serialu
    friend std::ostream& operator<<(std::ostream& lhs, const Series& rhs);
public:
    // Konstruktor standardowy
    Series();
    // Konstruktor z argumentami
    Series(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear, const std::string& newSeriesDescription, unsigned newEpisodeNumber, unsigned newSeasonsNumber);
    // Destruktor
    ~Series() override;

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
    bool operator==(const Series& rhs) const;

    // Metoda dodająca do kontenera recenzji obiekt newReview
    void insertNewReview(const Review& newReview) override;
    // Metoda dziedziczona po klasie abstrakcyjnej - w tej klasie nieużywana
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription) override;
    // Metoda ustalająca podstawowe dane o serialu
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription, unsigned newEpisodesNumber, unsigned newSeasonsNumber) override;

private:
    unsigned episodesNumber;
    unsigned seasonsNumber;
    std::string seriesDescription;
};

#endif //WYPOZYCZALNIAFILMOW_SERIES_H