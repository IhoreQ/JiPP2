//
// Created by IhoreQ on 08/12/2021.
//

#include "../include/Player.h"

using namespace std;

Player::Player() {}

void Player::playTheSong() {

    if (songsList.empty()) {
        cout << "Brak utworów na playliście!" << endl;
    }
    else {
        list<Song *>::iterator song = songsList.begin();

        cout << "Aktualnie gra: " << endl;
        cout << "Tytuł: " << (*song)->artist << " - " << (*song)->title << endl;
        cout << "Tekst utworu:" << endl << (*song)->text << endl;
    }
}

void Player::createPlaylist(list<Song>& songs) {

    if (songsList.size() == 0) {
        for (auto& x : songs)
            addSong(&x);
    }
    else {
        songsList.clear();
        for (auto& x : songs)
            addSong(&x);
    }
}

void Player::nextSong() {
    list<Song*>::iterator firstSong = songsList.begin();

    songsList.pop_front();
    songsList.push_back((*firstSong));
}

void Player::previousSong() {
    list<Song*>::iterator x = songsList.end();
    auto lastSong = prev(x, 1);
    songsList.pop_back();
    songsList.push_front(*lastSong);
}

void Player::addSong(Song* song) {
    songsList.push_back(song);
}

void Player::deleteSongFromPlaylist() {

    string titleToDelete;
    int i = 0;
    list<Song*>::iterator x = songsList.begin();

    cout << "Podaj tytuł utworu do usunięcia: ";
    getline(cin >> ws, titleToDelete);

    while (x != songsList.end()) {
        if (((*x)->title.compare(titleToDelete)) == 0) {
            songsList.erase(x++);
            i++;
        }
        else {
            ++x;
            i++;
        }
    }
    if (i == songsList.size())
        cout << "Nie znaleziono takiego utworu!" << endl;
}

void Player::showSongsList() {
    list<Song*>::iterator x;
    int i = 1;
    cout << "Lista utworów:" << endl;
    if (songsList.size() > 0) {
        for (x = songsList.begin(); x != songsList.end(); ++x) {
            cout << i << ". " << (*x)->artist << " - " << (*x)->title << endl;
            i++;
        }
        cout << "*****************" << endl;
    }
}

void Player::playSongsInLoop() {
    list<Song*>::iterator x;

    if (songsList.size() > 0) {
        cout << "Aktualnie gra: " << endl;
        for (x = songsList.begin(); x != songsList.end(); ++x) {
            cout << (*x)->artist << " - " << (*x)->title << endl << "Tekst utworu:" << endl << (*x)->text << endl;
            cout << "---" << endl;
        }
    }
}

bool Player::checkIfEmpty() {
    if (songsList.empty())
        return true;
    else
        return false;
}

void Player::addSongToPlaylist() {

    string newArtist, newTitle, newText;
    cout << "Podaj wykonawcę: ";
    getline(cin >> ws, newArtist);
    cout << "Podaj tytuł utworu: ";
    getline(cin >> ws, newTitle);
    cout << "Podaj tekst utworu: ";
    getline(cin >> ws, newText);

    Song* newSong = new Song(newTitle, newArtist, newText);
    addSong(newSong);
}