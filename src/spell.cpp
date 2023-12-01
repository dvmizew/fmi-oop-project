//
// Created by radud on 13.11.2023.
//

#include "../headers/spell.hpp"

std::ostream &operator<<(std::ostream &out, const spell &obj) {
    out << obj.brewTime << " brewing time and occupies " << obj.spaceOccupied;
    return out;
}

spell &spell::operator=(const spell &obj) {
    brewTime = obj.brewTime;
    spaceOccupied = obj.spaceOccupied;
    return *this;
}

void heal::cast(std::unique_ptr<troop> &tr) {
    std::cout << "Healing troop...\n";
    tr->increaseHealth(20);
}

void rage::cast(std::unique_ptr<troop> &tr) {
    std::cout << "Raging troop...\n";
    tr->increaseHealth(20);
}