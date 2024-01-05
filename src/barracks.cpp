//
// Created by radud on 05.01.2024.
//

#include "../headers/barracks.h"

// overloaded << operator for barracks class
std::ostream &operator<<(std::ostream &out, const barracks &obj) {
    // printing the barracks' info
    out << obj.trainingRate << " training rate and it has " << obj.availableTroops.size() << " available troops\n";
    return out;
}
