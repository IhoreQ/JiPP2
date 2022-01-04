//
// Created by IhoreQ on 01/01/2022.
//

#include <iostream>
#include "../include/Series.h"

using namespace std;

std::ostream &operator<<(ostream &lhs, const Series &rhs) {
    lhs << rhs.name << "\t" << rhs.genre << "\t" << rhs.publicationYear << "\t" << rhs.episodesNumber;
    return lhs;
}

// Konstruktory
Series::Series() : Recording() {
    episodesNumber = 0;
    seriesDescription = "";
}

Series::Series(const string &newName, const string &newGenre, unsigned int newPublicationYear,
               const string &newSeriesDescription, unsigned int newEpisodeNumber) : Recording(newName, newGenre, newPublicationYear)  {
    name = newName;
    genre = newGenre;
    publicationYear = newPublicationYear;
    seriesDescription = newSeriesDescription;
    episodesNumber = newEpisodeNumber;
}

Series::~Series() {}

void Series::setBorrowing(bool flag) {
    isBorrowed = flag;
}


