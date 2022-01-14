//
// Created by IhoreQ on 01/01/2022.
//

#include <iostream>
#include <iomanip>
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

    lhs  << rhs.name << setw(20) << rhs.genre << setw(20) << rhs.publicationYear;
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
        cout << "---------" << endl;
    }
}

void Film::setLoadedValues(const string& newName, const string& newGenre, unsigned newYear, const string& newDescription) {
    name = newName;
    genre = newGenre;
    publicationYear = newYear;
    filmDescription = newDescription;
}

void Film::setLoadedValues(const string &newName, const string &newGenre, unsigned int newYear, const string& newDescription, unsigned int newEpisodesNumber, unsigned int newSeasonsNumber) {}

void Film::insertNewReview(const Review &newReview) {
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