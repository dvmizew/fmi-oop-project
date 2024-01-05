//
// Created by radud on 05.01.2024.
//

#include "../headers/heal.h"

// defining what heal spell does to the troop
void heal::cast(std::unique_ptr<troop> &tr) {
    std::cout << "Healing troop...\n";
    // standard healing, might expand the functionality in the future
    tr->increaseHealth(20);
}