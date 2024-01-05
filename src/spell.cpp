//
// Created by radud on 13.11.2023.
//

#include "../headers/spell.hpp"

// overloading the << operator for printing out the info for spells
std::ostream &operator<<(std::ostream &out, const spell &obj) {
    // printing the spell's info
    out << obj.brewTime << " brewing time and occupies " << obj.spaceOccupied;
    return out;
}

// overloading the assignment operator
spell &spell::operator=(const spell &obj) {
    // checking if the object is not the same as the one we are assigning to
    brewTime = obj.brewTime;
    spaceOccupied = obj.spaceOccupied;
    return *this;
}