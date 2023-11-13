//
// Created by radud on 13.11.2023.
//

#include "../headers/construction.hpp"

// overloaded << operator for construction class
std::ostream &operator<<(std::ostream &out, const construction &obj) {
    out << obj.hp << " HP";
    return out;
}

// overloaded << operator for barracks class
std::ostream &operator<<(std::ostream &out, const barracks &obj) {
    out << obj.trainingRate << " training rate and it has " << obj.availableTroops.size() << " available troops\n";
    return out;
}