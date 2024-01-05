//
// Created by radud on 05.01.2024.
//

#include "../headers/giant.h"

void giant::attack(troop &enemyTroop) {
    std::cout << "Giant attacks!\n";
    // standard damage for a giant for the moment
    enemyTroop.decreaseHP(BASE_DAMAGE_GIANT);
}

void giant::die() {
    std::cout << "I wouldn't win anyway...\n";
}