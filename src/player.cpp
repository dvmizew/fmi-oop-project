//
// Created by radud on 13.11.2023.
//

#include <utility>
#include "../headers/custom_exceptions.hpp"
#include "../headers/player.hpp"
#include "../headers/barbarian.hpp"
#include "../headers/archer.hpp"
#include "../headers/giant.hpp"
#include "../headers/heal.hpp"
#include "../headers/rage.hpp"

// overloaded operator<< for printing the player's info
std::ostream &operator<<(std::ostream &out, const player &obj) {
    // printing the player's info
    out << "Town Hall level is: " << obj.townHallLevel;
    out << "\nName: " << obj.name << '\n';
    out << obj.xp << " XP\n" << obj.rank << " rank\n";
    out << "It unlocked " << obj.availableTroops << " troops and " << obj.availableSpells << " spells\n\n";
    return out;
}

unsigned int player::playerCount = 0;

// overloading the assignment operator
player &player::operator=(const player &obj) {
    // checking if the object is not the same as the one we are assigning to
    if (this != &obj) {
        this->xp = obj.xp;
        this->rank = obj.rank;
        this->availableTroops = obj.availableTroops;
        this->availableSpells = obj.availableSpells;
        this->townHallLevel = obj.townHallLevel;
        this->name = obj.name;
    }
    return *this; // returning the object
}

player player::createPlayer(unsigned int _xp, std::string _name) {
    // making sure that we could use the function by passing the arguments or by entering the name in console
    std::string playerName = std::move(_name); // moving the ownership of the string to the function
    if (playerName.empty()) { // if the name is empty, we ask the user to enter it
        std::cout << "Enter player name: ";
        std::cin >> playerName;
    }

    playerCount++;
    // the player should always start the game with 0 xp
    return {_xp, std::move(playerName)};
}

void player::viewCurrentArmy() {
    std::cout << "This is your army chief!\n";
    std::cout << "Troops: ";
    for (const auto &i: troops) {
        // counting the number of troops in the army
        unsigned int barbarianCount = 0, archerCount = 0, giantCount = 0;
        // checking if the troop is a barbarian, archer or giant and incrementing the counter
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
        // checking if the spell is a rage or heal and incrementing the counter
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
    troops.emplace_back(std::move(troop)); // moving the ownership of the troop pointer to the army
}

void player::addSpell(std::unique_ptr<spell> spell) {
    spells.emplace_back(std::move(spell)); // moving the ownership of the spell pointer to the army
}

template<typename ItemType>
std::unique_ptr<ItemType>
player::getItemAtIndex(size_t index, const std::vector<std::unique_ptr<ItemType>> &items) const {
    try {
        if (index >= items.size()) {
            throw InvalidIndexException();
        }

        std::unique_ptr<ItemType> clonedItem;
        if (items[index]) {
            clonedItem.reset(dynamic_cast<ItemType *>(items[index]->clone().release()));
        }
        return clonedItem;
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
        throw;
    }
}

void player::castCurrentSpell(std::unique_ptr<troop> &tr) {
    if (!currentSpell) { // if the current spell is a null pointer, we throw an exception
        throw NullPointerException();
    }

    currentSpell->cast(tr); // casting the spell on the troop
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

    try {
        // Get the first troop from the enemy and my army
        auto enemyTroop = enemyPlayer.getItemAtIndex(0, enemyPlayer.troops);
        auto myTroop = getItemAtIndex(0, troops);

        if (!enemyTroop || !myTroop) {
            throw NullPointerException();
        }

        // Attack the enemy troop using the attackEnemyTroop method
        attackEnemyTroop(enemyPlayer, 0, 0);

        // Check if the enemy player has spells
        auto enemySpell = enemyPlayer.getItemAtIndex(0, enemyPlayer.spells);
        if (enemyPlayer.spells.empty()) {
            throw NoSpellsException();
        }

        // Cast a spell on the enemy troop
        auto mySpell = getItemAtIndex(0, spells);
        castSpellOnTroop(myTroop, 0);
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
    }
    catch (NullPointerException &e) {
        std::cout << e.what();
    }
    catch (NoSpellsException &e) {
        std::cout << e.what();
    }
    catch (NoTroopsException &e) {
        std::cout << e.what();
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

void player::attackEnemyTroop(const player &enemyPlayer, size_t troopIndex, size_t enemyTroopIndex) {
    try {
        // checking if the both troops are in the bounds of the army of each player
        auto myTroop = getItemAtIndex(troopIndex, troops);
        auto enemyTroop = enemyPlayer.getItemAtIndex(enemyTroopIndex, enemyPlayer.troops);

        if (!myTroop || !enemyTroop) {
            throw NullPointerException();
        }

        // we finally attack
        myTroop->attack(*enemyTroop);
    }
    catch (InvalidIndexException &e) {
        std::cout << e.what();
    }
    catch (NullPointerException &e) {
        std::cout << e.what();
    }
}