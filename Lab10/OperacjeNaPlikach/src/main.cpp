#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> inputData(const string& line) {

    string word;
    vector<string> row;
    stringstream s(line);
    while (getline(s, word, ',')) {
        row.push_back(word);
    }
    return row;
}

int main() {

    ifstream readFile("data.csv");
    ofstream tramwaje("tramwaje.csv");
    ofstream autobusy("autobusy.csv");
    string line;
    string operatorAutobusow = "MPK S.A. w Krakowie";
    string operatorTramwajow = "ZTP  Kraków";

    int lineNumber;
    string startStop, endStop, lineOperator;
    vector<string> row;
    bool firstLine = true;

    if (!readFile.good() && !tramwaje.good() && !autobusy.good()) {
        cout << "Błąd podczas otwierania pliku!";
        exit(1);
    }
    if (readFile.is_open()) {
        while (getline(readFile, line)) {
                row = inputData(line);
                if (firstLine) {
                    tramwaje << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "\n";
                    autobusy << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "\n";
                    firstLine = false;
                }
                else {
                    lineNumber = stoi(row[0]);
                    lineNumber /= 100;
                    if (lineNumber == 0)
                        tramwaje << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "\n";
                    else if(lineNumber > 0)
                        autobusy << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "\n";
                }
        }
        readFile.close();
    }

    return 0;
}
