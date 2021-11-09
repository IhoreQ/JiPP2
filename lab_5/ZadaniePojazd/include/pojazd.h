using namespace std;

class Pojazd {
    string rejestracja;
    string nazwa;
    int iloscMiejsc;
    string* dane;
    string marka;
    static string najnowszaWersjaOprogramowania;
    string zainstalowanaWersjaOprogramowania;

public:
    Pojazd(string rejestracja, int iloscMiejsc, string nazwa, string marka);
    Pojazd(Pojazd& klasaPojazdu);
    ~Pojazd();
    void wypiszInformacje();
    void updateInfo(int nrMiejsca, string info);
    string getRejestracja();
    string getNazwa();
    string getMarka();
    void setNazwa(string nowaNazwa);
    void setRejestracja(string nowaRestracja);
    void wypiszWersjeOprogramowania();
    void zamienWersje();
    void opublikujNoweOprogramowanie(string nowaWersja);
};