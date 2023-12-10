//
// Created by radud on 13.11.2023.
//

#include "../headers/spell.hpp"

// overloading the << operator for printing out the info for spells
std::ostream &operator<<(std::ostream &out, const spell &obj) {
    out << obj.brewTime << " brewing time and occupies " << obj.spaceOccupied;
    return out;
}

// overloading the assignment operator
spell &spell::operator=(const spell &obj) {
    brewTime = obj.brewTime;
    spaceOccupied = obj.spaceOccupied;
    return *this;
}

// defining what heal spell does to the troop
void heal::cast(std::unique_ptr<troop> &tr) {
    std::cout << "Healing troop...\n";
    // standard healing, might expand the functionality in the future
    tr->increaseHealth(20);
}

// defining what raging a troop does
void rage::cast(std::unique_ptr<troop> &tr) {
    std::cout << "Raging troop...\n";
    // standard raging, might expand the functionality in the future
    tr->increaseSpeed(20);
}