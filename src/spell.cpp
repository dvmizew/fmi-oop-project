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

std::unique_ptr<heal> heal::cast_heal(std::unique_ptr<spell> sp) {
    // Check if the spell is a heal spell
    if (dynamic_cast<heal *>(sp.get())) {
        std::cout << "Healing troop...\n";
        return std::unique_ptr<heal>(dynamic_cast<heal *>(sp.release()));
    } else {
        std::cout << "Invalid spell for healing.\n";
        return nullptr;
    }
}