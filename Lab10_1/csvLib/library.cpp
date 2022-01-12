#include "library.h"

#include <iostream>

std::vector<std::vector<std::string>> csvRead(std::fstream* file) {

    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    if (file->is_open()) {
        while(getline((*file), line)) {
            row.clear();

            std::stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    } else {
        // TODO exception
    }

    file->close();
}

void csvWrite(std::fstream* file) {

}
