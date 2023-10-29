//
// Created by radud on 29.10.2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "troops.h"
#include "spells.h"
#include "constructions.h"

class player {
private:
    unsigned int xp{}, rank{}, available_troops{}, available_spells{}, town_hall_level{};
    std::string name{};
    std::vector<troop> troops;
    std::vector<spell> spells;

public:
    void viewCurrentArmy() {
        std::cout << "This is your army chief!\n";
        std::cout << "Troops: ";
        for (auto i : troops) {

        }
        std::cout << "\nSpells: ";
        for (auto i : spells) {

        }
    }

    void lookForBattle() {
        std::cout << "To the battle!\n";
    }

    friend std::ostream& operator<<(std::ostream &, const player&);
};

std::ostream& operator<<(std::ostream &out, const player& obj) {
    out << "Town Hall level is :" << obj.town_hall_level;
    out << "Name: " << obj.name;
    out << obj.xp << " XP " << obj.rank << " rank";
    out << "It unlocked " << obj.available_troops << " troops and " << obj.available_spells << " spells\n";
    return out;
}

#endif //OOP_PLAYER_H
