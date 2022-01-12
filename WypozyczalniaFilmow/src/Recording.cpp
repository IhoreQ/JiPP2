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
    reviewCount = 0;
    averageScore = 0.0;
}

Recording::Recording(const string& newName, const string& newGenre, unsigned newPublicationYear) {
    name = newName;
    genre = newGenre;
    publicationYear = newPublicationYear;
    reviewCount = 0;
    averageScore = 0.0;
}

Recording::~Recording() {}