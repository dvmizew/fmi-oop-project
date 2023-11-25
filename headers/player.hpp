//
// Created by radud on 29.10.2023.
//

#ifndef OOP_PLAYER_HPP
#define OOP_PLAYER_HPP

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include "troop.hpp"
#include "spell.hpp"
#include "construction.hpp"

class player {
private:
    unsigned int xp{}, rank{}, availableTroops{}, availableSpells{}, townHallLevel{};
    std::string name{};
    std::vector<std::unique_ptr<troop>> troops{}; // the player's army
    std::vector<std::unique_ptr<spell>> spells{}; // the player's spells

public:
    // init constructor
    player(unsigned int xp, unsigned int rank, unsigned int availableTroops, unsigned int availableSpells,
           unsigned int townHallLevel, std::string name,
           std::vector<std::unique_ptr<troop>> &&playerTroops,
           std::vector<std::unique_ptr<spell>> &&playerSpells)
            : xp(xp), rank(rank), availableTroops(availableTroops),
              availableSpells(availableSpells), townHallLevel(townHallLevel),
              name(std::move(name)), troops(std::move(playerTroops)), spells(std::move(playerSpells)) {}

    // destructor
    ~player() = default;

    // Prototypes
    void recruitTroop(std::unique_ptr<troop> newTroop);

    void brewSpell(std::unique_ptr<spell> newSpell);

    void viewCurrentArmy();

    void attackEnemyTroop(const player &enemyPlayer, unsigned int troopIndex, size_t enemyTroopIndex);

    static void lookForBattle();

    friend std::ostream &operator<<(std::ostream &, const player &);
};

// definition of the overloaded operator<< for showing in console the player's stats
std::ostream &operator<<(std::ostream &out, const player &obj);

#endif //OOP_PLAYER_HPP