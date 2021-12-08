//
// Created by IhoreQ on 08/12/2021.
//

#ifndef ODTWARZACZMUZYKI_PLAYER_H
#define ODTWARZACZMUZYKI_PLAYER_H

#include <iostream>
#include "Song.h"
#include <list>
#include <cstring>

class Player {

public:
    Player();
    void playTheSong();
    void createPlaylist(list<Song>& songs);
    void playSongsInLoop();
    void nextSong();
    void previousSong();
    void addSongToPlaylist();
    void addSong(Song* song);
    void deleteSongFromPlaylist();
    void showSongsList();
    bool checkIfEmpty();

private:
    list<Song*> songsList;

};

#endif //ODTWARZACZMUZYKI_PLAYER_H
