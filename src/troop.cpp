//
// Created by radud on 13.11.2023.
//

#include "../headers/troop.hpp"

std::ostream &operator<<(std::ostream &out, const troop &obj) {
    out << obj.hp << " HP, " << obj.damage << " damage, " << obj.trainingTime
        << " training time, and occupies " << obj.spaceOccupied << " spaces and it costs " << obj.elixirCost;
    if (obj.damageType)
        out << "Melee damage\n";
    else
        out << "Ranged damage\n";
    return out;
}

[[maybe_unused]] void troop::attack() {
    std::cout << "Attacking...\n";
}

[[maybe_unused]] void troop::train() {
    std::cout << "Training...\n";
}

[[maybe_unused]] void troop::die() {
    std::cout << "This troop is dead!\n";
    hp = 0;
}