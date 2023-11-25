//
// Created by radud on 13.11.2023.
//

#include "../headers/troop.hpp"

#define BASE_DAMAGE 10 // minimum damage a troop can deal
#define BASE_DAMAGE_BARB 15
#define BASE_DAMAGE_ARCH 12
#define BASE_DAMAGE_GIANT 20

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

// Implementation for virtual pure functions of derived classes
void barbarian::attack(troop &enemyTroop) {
    std::cout << "Barbarian attacks!\n";
    enemyTroop.decreaseHP(BASE_DAMAGE_BARB);
}

void barbarian::die() {
    std::cout << "Here I come, Valhalla\n";
}

void archer::attack(troop &enemyTroop) {
    std::cout << "Archer attacks!\n";
    enemyTroop.decreaseHP(BASE_DAMAGE_ARCH);
}

void archer::die() {
    std::cout << "\n";
}

void giant::attack(troop &enemyTroop) {
    std::cout << "Giant attacks!\n";
    enemyTroop.decreaseHP(BASE_DAMAGE_GIANT);
}

void giant::die() {
    std::cout << "I wouldn't win anyway...\n";
}