//
// Created by radud on 13.11.2023.
//

#include "../headers/construction.hpp"
#define BARRACKS_MAX_CAPACITY 20
#define SPELL_FACTORY_MAX_CAPACITY 10

// overloaded << operator for construction class
std::ostream &operator<<(std::ostream &out, const construction &obj) {
    out << obj.hp << " HP";
    return out;
}

construction &construction::operator=(const construction &obj) {
    if (this != &obj) {
        this->hp = obj.hp;
    }
    return *this;
}

// overloaded << operator for barracks class
std::ostream &operator<<(std::ostream &out, const barracks &obj) {
    out << obj.trainingRate << " training rate and it has " << obj.availableTroops.size() << " available troops\n";
    return out;
}

void barracks::trainTroop(std::unique_ptr<troop> newTroop) {
    if (availableTroops.size() < BARRACKS_MAX_CAPACITY)
        availableTroops.push_back(std::move(newTroop));
    else {
        std::cout << "The barracks is full. Please wait for a newTroop to be trained.\n";
    }
}

void spellFactory::brewSpell(std::unique_ptr<spell> newSpell) {
    if (availableSpells.size() < SPELL_FACTORY_MAX_CAPACITY)
        availableSpells.push_back(std::move(newSpell));
    else {
        std::cout << "The spell factory is full. Please wait for a spell to be brewed.\n";
    }
}