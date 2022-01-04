#ifndef WYPOZYCZALNIAFILMOW_FILM_H
#define WYPOZYCZALNIAFILMOW_FILM_H

#include "Recording.h"

class Film : public Recording {
    friend std::ostream& operator<<(std::ostream& lhs, const Film& rhs);
public:
    Film();
    Film(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear, const std::string& newFilmDescription);
    Film(std::string updateName, bool updateBorrowing, std::string updateGenre, unsigned updateReviewCount, double updateAverageScore, unsigned updatePublicationYear, std::vector<Review*> updateReviewList, const std::string& newFilmDescription);

    std::string getName() override;
    unsigned getReviewCount() override;
    std::string getGenre() override;
    double getAverageScore() override;
    unsigned getPublicationYear() override;
    std::string getDescription() override;

    void setBorrowing(bool flag) override;
    bool isBorrowing() override;

    void printDescription() const override;
    void printReviews() override;
    void incrementCounter() override;

    bool operator==(const Film& rhs) const;


private:
    std::string filmDescription;
};

#endif //WYPOZYCZALNIAFILMOW_FILM_H
