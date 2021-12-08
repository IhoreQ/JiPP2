//
// Created by IhoreQ on 07/12/2021.
//

#ifndef ODTWARZACZMUZYKI_SONG_H
#define ODTWARZACZMUZYKI_SONG_H

#include <iostream>

using namespace std;

class Song {
    friend class Player;
public:
    Song(const string& title, const string& artist, const string& text);

private:
    const string title;
    const string artist;
    const string text;
};

#endif //ODTWARZACZMUZYKI_SONG_H
