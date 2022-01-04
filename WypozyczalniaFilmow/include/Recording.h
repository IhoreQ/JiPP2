#ifndef WYPOZYCZALNIAFILMOW_RECORDING_H
#define WYPOZYCZALNIAFILMOW_RECORDING_H

#include <vector>
#include "Review.h"

class Recording {
public:

    Recording();
    Recording(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear);
    Recording(const std::string& updateName, bool updateBorrowing, const std::string& updateGenre, unsigned updateReviewCount, double updateAverageScore, unsigned updatePublicationYear, const std::vector<Review*>& updateReviewList);
    virtual ~Recording();

    // Gettery
    virtual std::string getName() = 0;
    virtual std::string getGenre() = 0;
    virtual unsigned getReviewCount() = 0;
    virtual double getAverageScore() = 0;
    virtual unsigned getPublicationYear() = 0;
    virtual std::string getDescription() = 0;
    virtual void setBorrowing(bool flag) = 0;
    virtual bool isBorrowing() = 0;

    virtual void printDescription() const = 0;
    virtual void printReviews() = 0;
    virtual void incrementCounter() = 0;

protected:
    std::string name;
    bool isBorrowed; // TODO usunąć to
    std::string genre;
    unsigned reviewCount;
    double averageScore;
    unsigned publicationYear;
    std::vector<Review> reviewList;
};

#endif //WYPOZYCZALNIAFILMOW_RECORDING_H
