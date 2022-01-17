//
// Created by IhoreQ on 01/01/2022.
//

#include <iostream>
#include <iomanip>
#include "../include/Series.h"
#include "../include/helpfulFunctions.h"

using namespace std;

std::ostream &operator<<(ostream &lhs, const Series &rhs) {
    lhs << rhs.name << setw(20) << rhs.genre << setw(20) << rhs.publicationYear << setw(20) << rhs.episodesNumber << setw(20) << rhs.seasonsNumber;
    return lhs;
}

// Konstruktory
Series::Series() : Recording() {
    episodesNumber = 0;
    seriesDescription = "";
}

Series::Series(const string &newName, const string &newGenre, unsigned int newPublicationYear,
               const string &newSeriesDescription, unsigned int newEpisodeNumber, unsigned newSeasonsNumber) : Recording(newName, newGenre, newPublicationYear)  {
    name = newName;
    genre = newGenre;
    publicationYear = newPublicationYear;
    seriesDescription = newSeriesDescription;
    episodesNumber = newEpisodeNumber;
    seasonsNumber = newSeasonsNumber;
}

Series::~Series() {}

// Gettery

string Series::getName() {
    return name;
}

unsigned Series::getReviewCount() {
    return reviewCount;
}

string Series::getGenre() {
    return genre;
}

double Series::getAverageScore() {
    return averageScore;
}

unsigned Series::getPublicationYear() {
    return publicationYear;
}

string Series::getDescription() {
    return seriesDescription;
}

void Series::printDescription() const {
    cout << seriesDescription << endl;
}

bool Series::operator==(const Series &rhs) const {
    if (name == rhs.name)
        return true;

    return false;
}

void Series::printReviews() {
    for (auto& review : reviewList) {
        cout << "Dodal: " << review.getWhoAdded() << endl;
        cout << "Ocena: " << review.getScore() << endl;
        cout << review.getContent() << endl;
        cout << "---------" << endl;
    }
}

void Series::setLoadedValues(const string &newName, const string &newGenre, unsigned int newYear, const string &newDescription) {}

void Series::setLoadedValues(const string &newName, const string &newGenre, unsigned int newYear, const string &newDescription, unsigned int newEpisodesNumber, unsigned int newSeasonsNumber) {
    name = newName;
    genre = newGenre;
    publicationYear = newYear;
    seriesDescription = newDescription;
    episodesNumber = newEpisodesNumber;
    seasonsNumber = newSeasonsNumber;
}

void Series::insertNewReview(const Review &newReview) {
    reviewList.push_back(newReview);
    reviewCount++;
    if (reviewCount > 2) {
        double sum = 0;
        for (auto& element : reviewList)
            sum += element.getScore();
        averageScore = sum / reviewCount;
    }
    else if (reviewCount == 2)
        averageScore = countAverage<double>(averageScore, newReview.getScore());
    else
        averageScore = newReview.getScore();
}
