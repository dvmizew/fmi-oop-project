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

// Factory Method Design Pattern
class player {
private:
    static unsigned int playerCount;
    unsigned int xp{}, rank{}, availableTroops{}, availableSpells{}, townHallLevel{};
    std::string name{};
    spell *currentSpell{};
    std::vector<std::unique_ptr<troop>> troops{}; // the player's army
    std::vector<std::unique_ptr<spell>> spells{}; // the player's spells

public:
    player(unsigned int _xp, std::string _name) : xp(_xp), name(std::move(_name)) {
        playerCount++;
        std::cout << "Player created! Name: " << name << '\n';
    }

    // Destructor
    ~player() = default;

    // Factory method
    static std::unique_ptr<player> createPlayer(unsigned int _xp, const std::string& _name);

    // Setters
    void setCurrentSpell(spell *ptr) {
        currentSpell = ptr;
    }

    // Getters
    template<typename ItemType>
    std::unique_ptr<ItemType> getItemAtIndex(size_t index, const std::vector<std::unique_ptr<ItemType>> &items) const;

    static unsigned int getPlayerCount();

    // Prototypes

    void castCurrentSpell(std::unique_ptr<troop> &tr);

    void viewCurrentArmy();

    void addTroop(std::unique_ptr<troop> troop);

    void addSpell(std::unique_ptr<spell> spell);

    void createArmy();

    void attackEnemyTroop(const player &enemyPlayer, size_t troopIndex, size_t enemyTroopIndex);

    void castSpellOnTroop(std::unique_ptr<troop> &tr, unsigned int spellIndex);

    void attackPlayer(player &enemyPlayer);

    player &operator=(const player &obj);

    friend std::ostream &operator<<(std::ostream &, const player &);
};

#endif //OOP_PLAYER_HPP