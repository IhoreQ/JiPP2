//
// Created by IhoreQ on 01/01/2022.
//

#include <iostream>
#include "../include/Film.h"
#include "../include/helpfulFunctions.h"

using namespace std;

// Konstruktory

Film::Film() : Recording() {
    filmDescription = "";
}

Film::Film(const string& newName, const string& newGenre, unsigned newPublicationYear, const string& newFilmDescription) : Recording(newName, newGenre, newPublicationYear) {
    filmDescription = newFilmDescription;
}

Film::Film(const string& updateName, const string& updateGenre, unsigned updateReviewCount, double updateAverageScore, unsigned updatePublicationYear, const vector<Review*>& updateReviewList, const string& newFilmDescription) : Recording() {
    filmDescription = newFilmDescription;
}

// Gettery

string Film::getName() {
    return name;
}

unsigned Film::getReviewCount() {
    return reviewCount;
}

string Film::getGenre() {
    return genre;
}

double Film::getAverageScore() {
    return averageScore;
}

unsigned Film::getPublicationYear() {
    return publicationYear;
}

string Film::getDescription() {
    return filmDescription;
}

void Film::printDescription() const {
    cout << filmDescription << endl;
}

std::ostream& operator<<(ostream &lhs, const Film &rhs) {

    lhs << rhs.name << "\t" << rhs.genre << "\t" << rhs.publicationYear;
    return lhs;
}

bool Film::operator==(const Film &rhs) const {
    if (name == rhs.name)
        return true;

    return false;
}

void Film::printReviews() {
    for (auto& review : reviewList) {
        cout << "Dodal: " << review.getWhoAdded() << endl;
        cout << "Ocena: " << review.getScore() << endl;
        cout << review.getContent() << endl;
    }
}

void Film::setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription) {
    name = newName;
    genre = newGenre;
    publicationYear = newYear;
    filmDescription = newDescription;
}

void Film::setLoadedValues(const string &newName, const string &newGenre, unsigned int newYear, const std::string& newDescription, unsigned int newEpisodesNumber, unsigned int newSeasonsNumber) {}

void Film::insertNewReview(const Review &newReview) {
    reviewList.push_back(newReview);
    reviewCount++;
    if (reviewCount > 1)
        averageScore = (newReview.getScore() + averageScore) / 2;
    else
        averageScore = newReview.getScore();
}