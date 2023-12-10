//
// Created by radud on 13.11.2023.
//

#include <utility>
#include "../headers/custom_exceptions.h"
#include "../headers/player.hpp"

// overloaded operator<< for printing the player's info
std::ostream &operator<<(std::ostream &out, const player &obj) {
    out << "Town Hall level is: " << obj.townHallLevel;
    out << "\nName: " << obj.name << '\n';
    out << obj.xp << " XP\n" << obj.rank << " rank\n";
    out << "It unlocked " << obj.availableTroops << " troops and " << obj.availableSpells << " spells\n\n";
    return out;
}

unsigned int player::playerCount = 0;

// overloading the assignment operator
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

player player::createPlayer(unsigned int _xp, std::string _name) {
    // making sure that we could use the function by passing the arguments or by entering the name in console
    std::string playerName = std::move(_name);
    if (playerName.empty()) {
        std::cout << "Enter player name: ";
        std::cin >> playerName;
    }

    playerCount++;
    // the player should always starts the game with 0 xp
    return {_xp, std::move(playerName)};
}

void player::viewCurrentArmy() {
    std::cout << "This is your army chief!\n";
    std::cout << "Troops: ";
    for (const auto &i: troops) {
        // counting the number of troops in the army
        unsigned int barbarianCount = 0, archerCount = 0, giantCount = 0;
        if (dynamic_cast<barbarian *>(i.get())) {
            barbarianCount++;
        } else if (dynamic_cast<archer *>(i.get())) {
            archerCount++;
        } else if (dynamic_cast<giant *>(i.get())) {
            giantCount++;
        }

        // printing out the troops after checking if they truly exist in the army
        if (barbarianCount)
            std::cout << barbarianCount << "x barbarians ";
        else if (archerCount)
            std::cout << archerCount << "x archers ";
        else if (giantCount)
            std::cout << giantCount << "x giants ";
    }

    std::cout << "\nSpells: ";
    for (const auto &i: spells) {
        // counting the number of spells in the army
        unsigned int rageCount = 0, healCount = 0;
        if (dynamic_cast<rage *>(i.get()))
            rageCount++;
        else if (dynamic_cast<heal *>(i.get()))
            healCount++;

        // printing out the spells after checking if they truly exist in the army
        if (rageCount)
            std::cout << rageCount << "x rage ";
        else if (healCount)
            std::cout << healCount << "x heal";
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

void player::castCurrentSpell(std::unique_ptr<troop> &tr) {
    if (!currentSpell) {
        throw NullPointerException();
    }

    currentSpell->cast(tr);
}

void player::createArmy() {
    std::cout << "Creating army...\n";
    // creating the troops
    std::unique_ptr<troop> newBarbarian = std::make_unique<barbarian>();
    std::unique_ptr<troop> newArcher = std::make_unique<archer>();
    std::unique_ptr<troop> newGiant = std::make_unique<giant>();

    // moving the ownership of the troop pointers to the army
    addTroop(std::move(newBarbarian));
    addTroop(std::move(newArcher));
    addTroop(std::move(newGiant));

    // creating the spells
    std::unique_ptr<spell> newRage = std::make_unique<rage>();
    std::unique_ptr<spell> newHeal = std::make_unique<heal>();

    // moving the ownership of the spell pointers to the army
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

    setCurrentSpell(spells[spellIndex].get());
    castCurrentSpell(tr);
}

void player::attackEnemyTroop(const player &enemyPlayer, unsigned int troopIndex, size_t enemyTroopIndex) {
    try {
        // checking if the both troops are in the bounds of the army of each player
        if (troopIndex >= troops.size() || enemyTroopIndex >= enemyPlayer.troops.size()) {
            throw InvalidIndexException();
        }
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
        return;
    }

    // setting the currentTroop and the enemyTroop as the ONES that will attack after we check that they exist
    const auto &currentTroop = troops[troopIndex];
    const auto &enemyTroop = enemyPlayer.troops[enemyTroopIndex];

    // checking that currentTroop and enemyTroop are not null pointers after all
    if (!currentTroop || !enemyTroop) {
        throw NullPointerException();
    }

    // we finally attack
    //troops[troopIndex]->attack(*enemyPlayer.troops[enemyTroopIndex]);
    currentTroop->attack(*enemyTroop);
}