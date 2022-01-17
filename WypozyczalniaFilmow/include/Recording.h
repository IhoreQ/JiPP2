// Plik zawiera klasę abstrakcyjną Recording, po której dziedziczą klasy Film oraz Series

#ifndef WYPOZYCZALNIAFILMOW_RECORDING_H
#define WYPOZYCZALNIAFILMOW_RECORDING_H

#include <vector>
#include "Review.h"

class Recording {
public:

    Recording();
    Recording(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear);
    virtual ~Recording();

    // Gettery
    virtual std::string getName() = 0;
    virtual std::string getGenre() = 0;
    virtual unsigned getReviewCount() = 0;
    virtual double getAverageScore() = 0;
    virtual unsigned getPublicationYear() = 0;
    virtual std::string getDescription() = 0;

    // Printery
    virtual void printDescription() const = 0;
    virtual void printReviews() = 0;

    virtual void insertNewReview(const Review& newReview) = 0;
    virtual void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription) = 0;
    virtual void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription, unsigned newEpisodesNumber, unsigned newSeasonsNumber) = 0;

protected:
    std::string name;
    std::string genre;
    unsigned reviewCount;
    double averageScore;
    unsigned publicationYear;
    std::vector<Review> reviewList;
};

#endif //WYPOZYCZALNIAFILMOW_RECORDING_H
