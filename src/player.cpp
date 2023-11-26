//
// Created by radud on 13.11.2023.
//

#include <utility>
#include "../headers/custom_exceptions.h"
#include "../headers/player.hpp"

player::player(unsigned int _xp, std::string _name) : xp(_xp), name(std::move(_name)) {}

std::ostream &operator<<(std::ostream &out, const player &obj) {
    out << "Town Hall level is: " << obj.townHallLevel;
    out << "\nName: " << obj.name << '\n';
    out << obj.xp << " XP\n" << obj.rank << " rank\n";
    out << "It unlocked " << obj.availableTroops << " troops and " << obj.availableSpells << " spells\n\n";
    return out;
}

void player::lookForBattle() {
    std::cout << "To the battle!\n";
}

void player::viewCurrentArmy() {
    std::cout << "This is your army chief!\n";
    std::cout << "Troops: ";
    for (const auto &i: troops) {
        std::cout << i << '\n';
    }
    std::cout << "\nSpells: ";
    for (const auto &i: spells) {
        std::cout << i << '\n';
    }
    std::cout << '\n';
}

void player::attackEnemyTroop(const player &enemyPlayer, unsigned int troopIndex, size_t enemyTroopIndex) {
    if (troopIndex >= troops.size() || enemyTroopIndex >= enemyPlayer.troops.size()) {
        throw InvalidIndexException();
    }

    const auto &currentTroop = troops[troopIndex];
    const auto &enemyTroop = enemyPlayer.troops[enemyTroopIndex];

    if (!currentTroop || !enemyTroop) {
        throw NullPointerException();
    }

    troops[troopIndex]->attack(*enemyPlayer.troops[enemyTroopIndex]);
}

player &player::operator=(const player &obj) {
    if (this != &obj) {
        this->xp = obj.xp;
        this->rank = obj.rank;
        this->availableTroops = obj.availableTroops;
        this->availableSpells = obj.availableSpells;
        this->townHallLevel = obj.townHallLevel;
        this->name = obj.name;
    }
    return *this;
}

void player::addTroop(std::unique_ptr<troop> troop) {
    troops.emplace_back(std::move(troop));
}

void player::addSpell(std::unique_ptr<spell> spell) {
    spells.emplace_back(std::move(spell));
}