//
// Created by radud on 05.01.2024.
//

#ifndef OOP_SPELLFACTORY_H
#define OOP_SPELLFACTORY_H

#include "construction.hpp"

class spellFactory : public construction {
private:
    //unsigned int brewingRate{};
    std::vector<std::unique_ptr<spell>> availableSpells{};
    std::queue<std::unique_ptr<spell>> spellsInQueue{};
public:
    explicit spellFactory(unsigned int hp) : construction(hp) {}

    ~spellFactory() = default;
};


#endif //OOP_SPELLFACTORY_H
