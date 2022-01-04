#ifndef WYPOZYCZALNIAFILMOW_REVIEW_H
#define WYPOZYCZALNIAFILMOW_REVIEW_H

class Review {
public:
    Review();
    Review(std::string, unsigned);
    Review(std::string, std::string, unsigned);

    void setWhoAdded(std::string name);
    std::string getWhoAdded();
    void setContent(std::string newContent);
    std::string getContent();
    void setScore(unsigned newScore);
    unsigned getScore();

private:
    std::string whoAdded;
    std::string content;
    unsigned score;
};

#endif //WYPOZYCZALNIAFILMOW_REVIEW_H
