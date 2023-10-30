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
    std::vector<troop> troops{};
    std::vector<spell> spells{};

public:
    player(unsigned int xp, unsigned int rank, unsigned int available_troops, unsigned int available_spells,
           unsigned int town_hall_level, std::string name, std::vector<troop> troops, std::vector<spell> spells)
            : xp(xp), rank(rank), available_troops(available_troops),
              available_spells(available_spells), town_hall_level(town_hall_level),
              name(std::move(name)), troops(std::move(troops)), spells(std::move(spells)) {}
    ~player() = default;

    void viewCurrentArmy() {
        std::cout << "This is your army chief!\n";
        std::cout << "Troops: ";
        for (const auto& i : troops) {
            std::cout << i << '\n';
        }
        std::cout << "\nSpells: ";
        for (const auto& i : spells) {
            std::cout << i << '\n';
        }
    }
    // to be added
    static void lookForBattle() {
        std::cout << "To the battle!\n";
    }

    friend std::ostream& operator<<(std::ostream &, const player&);
};

std::ostream& operator<<(std::ostream &out, const player& obj) {
    out << "Town Hall level is :" << obj.town_hall_level;
    out << "\nName: " << obj.name << '\n';
    out << obj.xp << " XP\n" << obj.rank << " rank\n";
    out << "It unlocked " << obj.available_troops << " troops and " << obj.available_spells << " spells\n\n";
    return out;
}

#endif //OOP_PLAYER_H
