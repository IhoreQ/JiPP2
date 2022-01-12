#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include "../include/helpfulFunctions.h"

using namespace std;

void checkInput(int& option, int leftBound, int rightBound) {

    int again = 1;
    while (again == 1) {
        try {
            cin >> option;
            if (cin.fail() || option < leftBound || option > rightBound)
                throw "Błędna wartość!";
            else {
                again = 0;
                // USUNALEM STAD CIN.IGNORE JAKBY CO
            }
        }
        catch (const char *error) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << error << endl;
            cout << "Wprowadź poprawną wartość: ";
        }
    }
}

bool findUser(const string& login) {

    //Sprawdzam czy istnieje już taki użytkownik
    bool foundUser = false;
    ifstream readFile("../Users.csv", ios::in);
    string line;
    vector<string> row;

    if (readFile.good()) {
        while (getline(readFile, line)) {
            row = breakTheLine(line);
            if (row[0] == login) {
                foundUser = true;
                break;
            }
        }
        readFile.close();
    } else {
        cout << "Błąd podczas otwierania pliku Users.csv!" << endl;
        exit(1);
    }
    return foundUser;
}

vector<string> breakTheLine(const string& line) {
    string word;
    stringstream s(line);
    vector<string> row;

    while (s >> ws) {
        if (s.peek() == '"') {
            s >> quoted(word);
            string discard;
            getline(s, discard, ',');
        } else {
            getline(s, word, ',');
        }

        row.push_back(word);
    }

    return row;
}