//
// Created by IhoreQ on 01/01/2022.
//

#include <iostream>
#include "../include/Review.h"
#include "../include/helpfulFunctions.h"

using namespace std;

Review::Review(): score(0) {}

Review::Review(string, unsigned) {

}

Review::Review(string, string, unsigned) {

}

void Review::setWhoAdded(const string& name) {
    whoAdded = name;
}

string Review::getWhoAdded() const {
    return whoAdded;
}

void Review::setContent(const string& newContent) {
    content = newContent;
}

string Review::getContent() const {
    return content;
}

void Review::setScore(unsigned newScore) {
    score = newScore;
}

unsigned Review::getScore() const {
    return score;
}

void Review::setLoadedValues(const string &newWhoAdded, const string &newContent, unsigned int newScore) {
    whoAdded = newWhoAdded;
    content = newContent;
    score = newScore;
}
