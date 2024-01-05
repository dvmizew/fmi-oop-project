//
// Created by radud on 13.11.2023.
//

#include "../headers/troop.hpp"

troop &troop::operator=(const troop &other) {
    if (this != &other) {
        hp = other.hp;
        damage = other.damage;
        trainingTime = other.trainingTime;
        spaceOccupied = other.spaceOccupied;
        elixirCost = other.elixirCost;
        damageType = other.damageType;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const troop &obj) {
    out << obj.hp << " HP, " << obj.damage << " damage, " << obj.trainingTime
        << " training time, and occupies " << obj.spaceOccupied << " spaces and it costs " << obj.elixirCost;
    if (obj.damageType)
        out << "Melee damage\n";
    else
        out << "Ranged damage\n";
    return out;
}

void troop::decreaseHP(unsigned int amount) {
    hp -= amount;
}

void troop::attack(troop &enemyTroop) {
    std::cout << "Attacking...\n";
    if (enemyTroop.hp > 0) {
        enemyTroop.decreaseHP(BASE_DAMAGE);
    }
    if (hp == 0) {
        enemyTroop.die();
    }
}

void troop::die() {
    if (this->hp == 0)
        std::cout << "This troop is dead!\n";
}

void troop::increaseHealth(unsigned int amount) {
    hp += amount;
}

void troop::increaseSpeed(unsigned int amount) {
    speed += amount;
}