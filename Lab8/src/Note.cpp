#include <iostream>
#include "../include/Note.h"

using namespace std;


Note::Note(string str): title(str) {}

Note::Note() {}

// pobieranie tytułu notatki
string Note::getTitle() {
    return title;
}

// Funkcja ustawiająca nowy tytuł
void Note::setTitle(string newTitle) {
    this->title = newTitle;
}


// Konstruktor dla TextNote, dziedziczy tytuł z klasy bazowej Note
TextNote::TextNote(string noteTitle, string newContent) : Note(noteTitle) {
    this->content = newContent;
}

// Pobieranie zawartości notatki
string TextNote::getContent() {
    return content;
}

// Ustawianie nowej zawartosci notatki
void TextNote::setContent() {
    string line;

    cout << "Wpisz nowa zawartosc notatki o tytule " << title << ": ";
    getline(cin, line);
    this->content = line;
}