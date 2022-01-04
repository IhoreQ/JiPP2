//
// Created by IhoreQ on 01/01/2022.
//

#include <iostream>
#include "../include/Film.h"

using namespace std;

// Konstruktory

Film::Film() : Recording() {
    filmDescription = "";
}

Film::Film(const string& newName, const string& newGenre, unsigned newPublicationYear, const string& newFilmDescription) : Recording(newName, newGenre, newPublicationYear) {
    filmDescription = newFilmDescription;
}

Film::Film(string updateName, bool updateBorrowing, string updateGenre, unsigned updateReviewCount, double updateAverageScore, unsigned updatePublicationYear, vector<Review*> updateReviewList,const string& newFilmDescription) : Recording() {
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

bool Film::isBorrowing() {
    return isBorrowed;
}

void Film::setBorrowing(bool flag) {
    isBorrowed = flag;
}

void Film::printDescription() const {
    cout << filmDescription << endl;
}

void Film::incrementCounter() {
    reviewCount++;
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

