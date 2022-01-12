#ifndef WYPOZYCZALNIAFILMOW_REVIEW_H
#define WYPOZYCZALNIAFILMOW_REVIEW_H

class Review {
public:
    Review();
    Review(std::string, unsigned);
    Review(std::string, std::string, unsigned);

    void setWhoAdded(const std::string& name);
    std::string getWhoAdded() const;
    void setContent(const std::string& newContent);
    std::string getContent() const;
    void setScore(unsigned newScore);
    unsigned getScore() const;
    void setLoadedValues(const std::string& newWhoAdded, const std::string& newContent, unsigned newScore);

private:
    std::string whoAdded;
    std::string content;
    unsigned score;
};

#endif //WYPOZYCZALNIAFILMOW_REVIEW_H
