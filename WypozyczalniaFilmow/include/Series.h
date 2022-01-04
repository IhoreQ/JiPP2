#ifndef WYPOZYCZALNIAFILMOW_SERIES_H
#define WYPOZYCZALNIAFILMOW_SERIES_H

#include "Recording.h"

class Series : public Recording {
    friend std::ostream& operator<<(std::ostream& lhs, const Series& rhs);
public:
    Series();
    Series(const std::string& newName, const std::string& newGenre, unsigned newPublicationYear, const std::string& newSeriesDescription, unsigned newEpisodeNumber);
    ~Series() override;

    void setBorrowing(bool flag) override;
private:
    unsigned episodesNumber;
    std::string seriesDescription;
};

#endif //WYPOZYCZALNIAFILMOW_SERIES_H

// TODO Zrób cały plik