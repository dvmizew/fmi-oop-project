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
    static unsigned int playerCount;
    unsigned int xp{}, rank{}, availableTroops{}, availableSpells{}, townHallLevel{};
    std::string name{};
    spell *currentSpell{};
    std::vector<std::unique_ptr<troop>> troops{}; // the player's army
    std::vector<std::unique_ptr<spell>> spells{}; // the player's spells

public:
    // init constructor
    player(unsigned int _xp, std::string _name) : xp(_xp), name(std::move(_name)) {
        std::cout << "Player created! Name: " << name << '\n';
    }

    // destructor
    ~player() = default;

    static player createPlayer(unsigned int _xp, std::string _name);

    // setters
    void setCurrentSpell(spell *ptr) {
        currentSpell = ptr;
    }

    // getters
    [[nodiscard]] std::unique_ptr<troop> getTroopAtIndex(size_t index) const;

    [[nodiscard]] std::unique_ptr<spell> getSpellAtIndex(size_t index) const;

    static unsigned int getPlayerCount() {
        return playerCount;
    }

    void castCurrentSpell(std::unique_ptr<troop> &tr);

    // Prototypes
    void viewCurrentArmy();

    void addTroop(std::unique_ptr<troop> troop);

    void addSpell(std::unique_ptr<spell> spell);

    void createArmy();

    void attackEnemyTroop(const player &enemyPlayer, unsigned int troopIndex, size_t enemyTroopIndex);

    void castSpellOnTroop(std::unique_ptr<troop> &tr, unsigned int spellIndex);

    void attackPlayer(player &enemyPlayer);

    player &operator=(const player &obj);

    friend std::ostream &operator<<(std::ostream &, const player &);
};

#endif //OOP_PLAYER_HPP