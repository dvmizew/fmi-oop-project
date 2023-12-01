//
// Created by radud on 13.11.2023.
//

#include <utility>
#include "../headers/custom_exceptions.h"
#include "../headers/player.hpp"

std::ostream &operator<<(std::ostream &out, const player &obj) {
    out << "Town Hall level is: " << obj.townHallLevel;
    out << "\nName: " << obj.name << '\n';
    out << obj.xp << " XP\n" << obj.rank << " rank\n";
    out << "It unlocked " << obj.availableTroops << " troops and " << obj.availableSpells << " spells\n\n";
    return out;
}

unsigned int player::playerCount = 0;

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

void player::addTroop(std::unique_ptr<troop> troop) {
    troops.emplace_back(std::move(troop));
}

void player::addSpell(std::unique_ptr<spell> spell) {
    spells.emplace_back(std::move(spell));
}

std::unique_ptr<troop> player::getTroopAtIndex(size_t index) const {
    try {
        if (index >= troops.size()) {
            throw InvalidIndexException();
        }

        std::unique_ptr<troop> clonedTroop;
        if (troops[index]) {
            clonedTroop.reset(dynamic_cast<troop *>(troops[index]->clone().release()));
        }
        return clonedTroop;
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
        throw;
    }
}

std::unique_ptr<spell> player::getSpellAtIndex(size_t index) const {
    try {
        if (index >= spells.size()) {
            throw InvalidIndexException();
        }

        std::unique_ptr<spell> clonedSpell;
        if (spells[index]) {
            clonedSpell.reset(dynamic_cast<spell *>(spells[index]->clone().release()));
        }
        return clonedSpell;
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
        throw;
    }
}

void player::createArmy() {
    std::cout << "Creating army...\n";
    // adding troops and spells to the players
    std::unique_ptr<troop> newBarbarian = std::make_unique<barbarian>();
    std::unique_ptr<troop> newArcher = std::make_unique<archer>();
    std::unique_ptr<troop> newGiant = std::make_unique<giant>();

    addTroop(std::move(newBarbarian));
    addTroop(std::move(newArcher));
    addTroop(std::move(newGiant));

    std::unique_ptr<spell> newRage = std::make_unique<rage>();
    std::unique_ptr<spell> newHeal = std::make_unique<heal>();

    addSpell(std::move(newRage));
    addSpell(std::move(newHeal));

    std::cout << "Army created successfully!\n";
}

void player::attackPlayer(player &enemyPlayer) {
    std::cout << "To the battle!\n";
    // check if the player has troops
    if (enemyPlayer.getTroopAtIndex(0)) {
        // attack the enemy player
        attackEnemyTroop(enemyPlayer, 0, 0);
    } else {
        throw NoTroopsException();
    }

    // check if the player has spells
    if (enemyPlayer.getSpellAtIndex(0)) {
        // cast a spell on the enemy player
        castSpellOnTroop(enemyPlayer.troops[0], 0);
    } else {
        throw NoSpellsException();
    }
}

void player::castSpellOnTroop(std::unique_ptr<troop> &tr, unsigned int spellIndex) {
    // check if the spell is valid
    try {
        if (spellIndex >= spells.size()) {
            throw InvalidIndexException();
        }
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
        return;
    }

    // check if the troop is valid
    if (!tr) {
        throw NullPointerException();
    }

    // check if the spell is heal
    if (dynamic_cast<heal *>(spells[spellIndex].get())) {
        std::cout << "Healing troop...\n";
        spells[spellIndex]->cast(tr);
    } else if (dynamic_cast<rage *>(spells[spellIndex].get())) {
        std::cout << "Raging troop...\n";
        spells[spellIndex]->cast(tr);
    } else {
        std::cout << "Invalid spell!\n";
    }
}

void player::attackEnemyTroop(const player &enemyPlayer, unsigned int troopIndex, size_t enemyTroopIndex) {
    try {
        if (troopIndex >= troops.size() || enemyTroopIndex >= enemyPlayer.troops.size()) {
            throw InvalidIndexException();
        }
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
        return;
    }

    const auto &currentTroop = troops[troopIndex];
    const auto &enemyTroop = enemyPlayer.troops[enemyTroopIndex];

    if (!currentTroop || !enemyTroop) {
        throw NullPointerException();
    }

    troops[troopIndex]->attack(*enemyPlayer.troops[enemyTroopIndex]);
}