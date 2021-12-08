#include <iostream>
#include <list>
#include "../include/Song.h"
#include "../include/Player.h"

using namespace std;

void showMenu();
void addNewSongToList(list<Song>& songsList, const string& title, const string& artist, const string& text);
void pause();

int main() {

    int option;
    bool playInLoop = false;
    list<Song> songsList;
    list<Song>::iterator song;
    Player SzantyPlayer;

    addNewSongToList(songsList, "Bitwa", "Mechanicy Szant", "Okręt nasz wpłynął w mgłę i fregaty dwie!");
    addNewSongToList(songsList, "A ty walcz!", "Róża Wiatrów", "A ty walcz! Za zwycięstwo w bitwie tej!");
    addNewSongToList(songsList, "Hej słońce", "Mordewind", "Hej słońce, hej kwiaty, a morze zazdrosne o chłopców żonatych");

    while (1) {

        system("clear"); // dla Linuxa
        //system("cls"); // dla Windowsa

        cout << "SzantyPlayer v1.0" << endl;
        cout << "*****************" << endl;
        SzantyPlayer.showSongsList();

        if (playInLoop) {
            SzantyPlayer.playSongsInLoop();
            playInLoop = false;
        }
        else
            SzantyPlayer.playTheSong();

        cout << "*****************" << endl;
        showMenu();
        cout << "Opcja: ";
        cin >> option;
        switch (option) {

            case 1:
                SzantyPlayer.createPlaylist(songsList);
                break;
            case 2:
                SzantyPlayer.addSongToPlaylist();
                break;
            case 3:
                if (SzantyPlayer.checkIfEmpty()) {
                    cout << "Brak utworów na playliście!" << endl;
                    pause();
                }
                else
                    SzantyPlayer.deleteSongFromPlaylist();
                break;
            case 4:
                if (SzantyPlayer.checkIfEmpty()) {
                    cout << "Brak utworów na playliście!" << endl;
                    pause();
                }
                else
                    playInLoop = true;
                break;
            case 5:
                if (SzantyPlayer.checkIfEmpty()) {
                    cout << "Brak utworów na playliście!" << endl;
                    pause();
                }
                else
                    SzantyPlayer.nextSong();
                break;
            case 6:
                if (SzantyPlayer.checkIfEmpty()) {
                    cout << "Brak utworów na playliście!" << endl;
                    pause();
                }
                else
                    SzantyPlayer.previousSong();
                break;
            case 7:
                cout << "Zakończono program." << endl;
                exit(1);
            default:
                cout << "Wprowadzono błędną opcję!" << endl;
                pause();
                break;
        }
    }
    return 0;
}

void showMenu() {

    cout << "Wybierz opcję: " << endl;
    cout << "1 - Utwórz listę odtwarzania, korzystając z wielu utworów" << endl;
    cout << "2 - Wstaw nowy utwór do listy odtwarzania." << endl;
    cout << "3 - Usuń utwór z listy odtwarzania" << endl;
    cout << "4 - Odtwarzaj utwory w pętli" << endl;
    cout << "5 - Następny utwór" << endl;
    cout << "6 - Poprzedni utwór" << endl;
    cout << "7 - Wyłącz odtwarzacz." << endl;
}

void addNewSongToList(list<Song>& songsList, const string& title, const string& artist, const string& text) {

    Song song(title, artist, text);
    songsList.push_back(song);
}

void pause() {
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
}