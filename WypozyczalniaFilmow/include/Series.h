#ifndef WYPOZYCZALNIAFILMOW_SERIES_H
#define WYPOZYCZALNIAFILMOW_SERIES_H

#include "Recording.h"

class Series : public Recording {
    friend std::ostream& operator<<(std::ostream& lhs, const Series& rhs);
public:
    Series();
    Series(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear, const std::string& newSeriesDescription, unsigned newEpisodeNumber, unsigned newSeasonsNumber);
    ~Series() override;

    std::string getName() override;
    unsigned getReviewCount() override;
    std::string getGenre() override;
    double getAverageScore() override;
    unsigned getPublicationYear() override;
    std::string getDescription() override;

    void printDescription() const override;
    void printReviews() override;

    bool operator==(const Series& rhs) const;

    void insertNewReview(const Review& newReview) override;
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription) override;
    void setLoadedValues(const std::string& newName, const std::string& newGenre, unsigned newYear, const std::string& newDescription, unsigned newEpisodesNumber, unsigned newSeasonsNumber) override;

private:
    unsigned episodesNumber;
    unsigned seasonsNumber;
    std::string seriesDescription;
};

#endif //WYPOZYCZALNIAFILMOW_SERIES_H

// TODO Zrób cały plik