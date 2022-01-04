//
// Created by IhoreQ on 01/01/2022.
//
#include <iostream>
#include "../include/Recording.h"

using namespace std;

// Konstruktory

Recording::Recording() {
    name = "";
    genre = "";
    publicationYear = 0;
    isBorrowed = false;
    reviewCount = 0;
    averageScore = 0.0;
}

Recording::Recording(const string& newName, const string& newGenre, unsigned newPublicationYear) {
    name = newName;
    genre = newGenre;
    publicationYear = newPublicationYear;

    isBorrowed = false;
    reviewCount = 0;
    averageScore = 0.0;
}

Recording::Recording(const string& updateName, bool updateBorrowing, const string& updateGenre, unsigned updateReviewCount, double updateAverageScore, unsigned updatePublicationYear, const vector<Review*>& updateReviewList): name(updateName), isBorrowed(updateBorrowing), genre(updateGenre), reviewCount(updateReviewCount), averageScore(updateAverageScore), publicationYear(updatePublicationYear), reviewList(updateReviewList) {}

Recording::~Recording() {}