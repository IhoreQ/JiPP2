#ifndef WYPOZYCZALNIAFILMOW_FILM_H
#define WYPOZYCZALNIAFILMOW_FILM_H

#include "Recording.h"

class Film : public Recording {
    friend std::ostream& operator<<(std::ostream& lhs, const Film& rhs);
public:
    Film();
    Film(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear, const std::string& newFilmDescription);

    std::string getName() override;
    unsigned getReviewCount() override;
    std::string getGenre() override;
    double getAverageScore() override;
    unsigned getPublicationYear() override;
    std::string getDescription() override;

    void printDescription() const override;
    void printReviews() override;

    bool operator==(const Film& rhs) const;

    void insertNewReview(const Review& newReview) override;
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription) override;
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription, unsigned newEpisodesNumber, unsigned newSeasonsNumber) override;

private:
    std::string filmDescription;
};

#endif //WYPOZYCZALNIAFILMOW_FILM_H
