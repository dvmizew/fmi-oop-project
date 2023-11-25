//
// Created by radud on 13.11.2023.
//

#include "../headers/player.hpp"

std::ostream &operator<<(std::ostream &out, const player &obj) {
    out << "Town Hall level is: " << obj.townHallLevel;
    out << "\nName: " << obj.name << '\n';
    out << obj.xp << " XP\n" << obj.rank << " rank\n";
    out << "It unlocked " << obj.availableTroops << " troops and " << obj.availableSpells << " spells\n\n";
    return out;
}

void player::recruitTroop(std::unique_ptr<troop> newTroop) {
    troops.push_back(std::move(newTroop));
    availableTroops++;
}

void player::brewSpell(std::unique_ptr<spell> newSpell) {
    spells.push_back(std::move(newSpell));
    availableSpells++;
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