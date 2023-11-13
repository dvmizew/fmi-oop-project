//
// Created by radud on 29.10.2023.
//

#ifndef OOP_PLAYER_HPP
#define OOP_PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "troop.hpp"
#include "spell.hpp"
#include "construction.hpp"

class player {
private:
    unsigned int xp{}, rank{}, availableTroops{}, availableSpells{}, townHallLevel{};
    std::string name{};
    std::vector<troop> troops{}; // the player's army
    std::vector<spell> spells{}; // the player's spells

public:
    // init constructor
    player(unsigned int xp, unsigned int rank, unsigned int availableTroops, unsigned int availableSpells,
           unsigned int townHallLevel, const std::string &name, const std::vector<troop> &troops,
           const std::vector<spell> &spells)
            : xp(xp), rank(rank), availableTroops(availableTroops),
              availableSpells(availableSpells), townHallLevel(townHallLevel),
              name(name), troops(troops), spells(spells) {}

    // destructor
    ~player() = default;

    // Prototypes
    void viewCurrentArmy();

    static void lookForBattle();

    friend std::ostream &operator<<(std::ostream &, const player &);
};

// definition of the overloaded operator<< for showing in console the player's stats
std::ostream &operator<<(std::ostream &out, const player &obj);

#endif //OOP_PLAYER_HPP