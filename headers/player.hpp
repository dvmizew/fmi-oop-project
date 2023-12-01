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
    player(unsigned int _xp, std::string _name) : xp(_xp), name(std::move(_name)) {}

    // destructor
    ~player() = default;

    // getters

    [[nodiscard]] std::unique_ptr<troop> getTroopAtIndex(size_t index) const;

    [[nodiscard]] std::unique_ptr<spell> getSpellAtIndex(size_t index) const;

    // Prototypes
    void viewCurrentArmy();

    void addTroop(std::unique_ptr<troop> troop);

    void addSpell(std::unique_ptr<spell> spell);

    void attackEnemyTroop(const player &enemyPlayer, unsigned int troopIndex, size_t enemyTroopIndex);

    static void lookForBattle();

    player &operator=(const player &obj);

    friend std::ostream &operator<<(std::ostream &, const player &);
};

// definition of the overloaded operator<< for showing in console the player's stats
std::ostream &operator<<(std::ostream &out, const player &obj);

#endif //OOP_PLAYER_HPP