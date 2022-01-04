#include <iostream>
#include <fstream>
#include <limits>

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
    ifstream readFile("Users.txt", ios::in);
    string line;
    if (readFile.good()) {
        while (getline(readFile, line)) {
            if (line.find(login) != string::npos)
                foundUser = true;
        }
        readFile.close();
    } else {
        cout << "Błąd podczas otwierania pliku Users.txt!" << endl;
        exit(1);
    }
    return foundUser;
}