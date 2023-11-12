//
// Created by radud on 29.10.2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "troop.h"
#include "spell.h"
#include "construction.h"

class player {
private:
    unsigned int xp{}, rank{}, availableTroops{}, availableSpells{}, townHallLevel{};
    std::string name{};
    std::vector<troop> troops{}; // the player's army
    std::vector<spell> spells{}; // the player's spells

public:
    // init constructor
    player(unsigned int xp, unsigned int rank, unsigned int availableTroops, unsigned int availableSpells,
           unsigned int townHallLevel, const std::string& name, const std::vector<troop>& troops, const std::vector<spell>& spells)
            : xp(xp), rank(rank), availableTroops(availableTroops),
              availableSpells(availableSpells), townHallLevel(townHallLevel),
              name(name), troops(troops), spells(spells) {}

    // destructor
    ~player() = default;

    // this function shows the current army of the player
    void viewCurrentArmy() {
        std::cout << "This is your army chief!\n";
        std::cout << "Troops: ";
        for (const auto &i: troops) {
            std::cout << i << '\n';
        }
        std::cout << "\nSpells: ";
        for (const auto &i: spells) {
            std::cout << i << '\n';
        }
    }

    // to be added
    static void lookForBattle() {
        std::cout << "To the battle!\n";
    }

    friend std::ostream &operator<<(std::ostream &, const player &);
};

// definition of the overloaded operator<< for showing in console the player's stats
std::ostream &operator<<(std::ostream &out, const player &obj) {
    out << "Town Hall level is :" << obj.townHallLevel;
    out << "\nName: " << obj.name << '\n';
    out << obj.xp << " XP\n" << obj.rank << " rank\n";
    out << "It unlocked " << obj.availableTroops << " troops and " << obj.availableSpells << " spells\n\n";
    return out;
}

#endif //OOP_PLAYER_H
