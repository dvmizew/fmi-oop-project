//
// Created by radud on 05.01.2024.
//

#include "../headers/archer.hpp"

void archer::attack(troop &enemyTroop) {
    std::cout << "Archer attacks!\n";
    // standard damage for an archer for the moment
    enemyTroop.decreaseHP(BASE_DAMAGE_ARCH);
}

void archer::die() {
    std::cout << "I'm going to Valhalla!\n";
}