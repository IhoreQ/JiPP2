using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    int numerAlbumu;
    int liczbaPytan;
    int poprawneOdpowiedzi;

public:
    string getImie();
    string getNazwisko();
    int getNumerAlbumu();
    int getLiczbaPytan();
    int getPoprawneOdpowiedzi();
    void setImie(string imie);
    void setNazwisko(string nazwisko);
    void setNumerAlbumu(int numerAlbumu);
    void setLiczbaPytan(int liczbaPytan);
    void setPoprawneOdpowiedzi(int poprawneOdpowiedzi);
    void wczytajDane();
    double procentPoprawnych();
};