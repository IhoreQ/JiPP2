// Plik recenzji - zawiera funkcje do ustalania wartości dla recenzji oraz ich pobieranie

#ifndef WYPOZYCZALNIAFILMOW_REVIEW_H
#define WYPOZYCZALNIAFILMOW_REVIEW_H

class Review {
public:
    // Konstruktor
    Review();
    // Konstruktor z argumentami
    Review(const std::string& newWhoAdded, const std::string& newContent, unsigned newScore);

    // Ustalenie dodającego
    void setWhoAdded(const std::string& name);
    // Pobranie dodającego
    std::string getWhoAdded() const;
    // Ustalenie zawartości
    void setContent(const std::string& newContent);
    // Pobranie zawartości
    std::string getContent() const;
    // Ustalenie oceny
    void setScore(unsigned newScore);
    // Pobranie oceny
    unsigned getScore() const;
    // Metoda ustalająca wartości dla obiektu
    void setLoadedValues(const std::string& newWhoAdded, const std::string& newContent, unsigned newScore);

private:
    std::string whoAdded;
    std::string content;
    unsigned score;
};

#endif //WYPOZYCZALNIAFILMOW_REVIEW_H
