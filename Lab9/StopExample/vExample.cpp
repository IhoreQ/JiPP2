//
// Created by Filip on 05.12.2021.
//

#include <iostream>
#include <vector>
#include "Stop.h"
#include "Line.h"

using namespace std;

int main() {
    vector<Stop> stops;

    vector<Stop>::iterator x;
    stops.reserve(20);
    stops.emplace_back(1, "Politechnika", 50.1, 50.2);
    stops.emplace_back(2, "Nowy Kleparz", 50.2, 50.2);
    stops.emplace_back(3, "Plac Inwalidów", 50.2, 50.2);
    stops.emplace_back(4, "Urzędnicza", 50.2, 50.2);
    stops.emplace_back(5, "Biprostal", 50.2, 50.2);
    stops.emplace_back(6, "Uniwersytet Pedagogiczny", 50.2, 50.2);

    Line l1("P", "Podchorążych");

    for (x = stops.begin(); x != stops.end(); ++x) {
        l1.addStop(&(*x));
    }

    l1.print();

    vector<Stop>::iterator iStart = stops.end();
    auto beforeAmount = stops.size();

    cout << "---------------------------------------" << endl;
    stops.emplace_back(7, "Bratysławska", 50.2, 50.2);
    stops.emplace_back(8, "Teatr Bagatela", 50.2, 50.2);
    stops.emplace_back(9, "Stary Kleparz", 50.2, 50.2);
    stops.emplace_back(10, "Teatr Słowackiego", 50.2, 50.2);
    stops.emplace_back(11, "Teatr Słowackiego1", 50.2, 50.2);
    stops.emplace_back(12, "Teatr Słowackiego2", 50.2, 50.2);
    stops.emplace_back(13, "Teatr Słowackiego3", 50.2, 50.2);

    auto newStopsAmount = stops.size() - beforeAmount;

    auto iStop = next(iStart, newStopsAmount);

    for (iStart; iStart != iStop; ++iStart)
        l1.addStop(&(*iStart));

    l1.print();

    stops.shrink_to_fit();
    cout << "---------------------------------------" << endl;
    stops[0].print();
    stops[1].print();
    stops[2].print();

    return 0;
}

