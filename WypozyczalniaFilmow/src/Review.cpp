//
// Created by IhoreQ on 01/01/2022.
//

#include <iostream>
#include "../include/Review.h"

using namespace std;

Review::Review(): score(0) {}

Review::Review(string, unsigned) {

}

Review::Review(string, string, unsigned) {

}

void Review::setWhoAdded(string name) {

}

string Review::getWhoAdded() {
    return whoAdded;
}

void Review::setContent(string newContent) {

}

string Review::getContent() {
    return content;
}

void Review::setScore(unsigned newScore) {

}

unsigned Review::getScore() {
    return score;
}
