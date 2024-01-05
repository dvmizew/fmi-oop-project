//
// Created by radud on 05.01.2024.
//

#include "../headers/rage.hpp"

// defining what raging a troop does
void rage::cast(std::unique_ptr<troop> &tr) {
    std::cout << "Raging troop...\n";
    // standard raging, might expand the functionality in the future
    tr->increaseSpeed(20);
}