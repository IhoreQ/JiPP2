//
// Created by IhoreQ on 30/11/2021.
//
using namespace std;

#ifndef LAB8_NOTE_H
#define LAB8_NOTE_H

class Note {
public:
    Note();
    Note(string str);
    string getTitle();
    void setTitle(string newTitle);
    virtual string getContent() = 0;
    virtual void setContent() = 0;

protected:
    string title;
};

class TextNote : public Note {
public:
    TextNote(string noteTitle, string newContent);
    string getContent() override;
    void setContent() override;

private:
    string content;
};

class NoteDirector {
public:

};

#endif //LAB8_NOTE_H
