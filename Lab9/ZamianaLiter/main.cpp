#include <iostream>
#include <list>

using namespace std;

int main() {

    list<string> litery = {"Jestem Laska, z Polski", "Szczotka, pasta, kubek, ciepła woda"};

    list<string>::iterator x;

    cout << "Małe litery: " << endl;
    for (x = litery.begin(); x != litery.end(); ++x)
        cout << (*x) << endl;

    cout << endl;

    for (x = litery.begin(); x != litery.end(); ++x) {
        for (auto& c : (*x))
            c = toupper(c);
    }

    cout << "Duże litery: " << endl;
    for (x = litery.begin(); x != litery.end(); ++x)
        cout << (*x) << " " << endl;

    return 0;
}
