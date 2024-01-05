//
// Created by radud on 05.01.2024.
//

#include "../headers/barbarian.hpp"

void barbarian::attack(troop &enemyTroop) {
    std::cout << "Barbarian attacks!\n";
    // standard damage for a barbarian for the moment
    enemyTroop.decreaseHP(BASE_DAMAGE_BARB);
}

void barbarian::die() {
    std::cout << "Here I come, Valhalla\n";
}