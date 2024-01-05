//
// Created by radud on 13.11.2023.
//

#include "../headers/troop.hpp"

troop &troop::operator=(const troop &other) {
    // checking if the object is not the same as the one we are assigning to
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
    // printing the troop's info
    out << obj.hp << " HP, " << obj.damage << " damage, " << obj.trainingTime
        << " training time, and occupies " << obj.spaceOccupied << " spaces and it costs " << obj.elixirCost;
    if (obj.damageType)
        out << "Melee damage\n";
    else
        out << "Ranged damage\n";
    return out;
}

void troop::decreaseHP(unsigned int amount) {
    hp -= amount; // decreasing the hp by the amount of damage taken
}

void troop::attack(troop &enemyTroop) {
    std::cout << "Attacking...\n";
    if (enemyTroop.hp > 0) { // if the enemy troop is not dead
        enemyTroop.decreaseHP(BASE_DAMAGE); // decrease the enemy troop's hp by the base damage
    }
    if (hp == 0) { // if the troop is dead
        enemyTroop.die();
    }
}

void troop::die() {
    if (this->hp == 0)
        std::cout << "This troop is dead!\n";
}

void troop::increaseHealth(unsigned int amount) {
    hp += amount; // increasing the hp by the amount of health in the parameter
}

void troop::increaseSpeed(unsigned int amount) {
    speed += amount; // increasing the speed
}