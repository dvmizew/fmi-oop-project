//
// Created by radud on 05.01.2024.
//

#ifndef OOP_BARBARIAN_HPP
#define OOP_BARBARIAN_HPP
#include "troop.hpp"

class barbarian : public troop {
public:
    barbarian() : troop(100, BASE_DAMAGE_BARB, 0, 1, true, 50, 2) {
        std::cout << "Barbarian created!\n";
    }

    std::unique_ptr<troop> clone() override {
        return std::make_unique<barbarian>(*this);
    }

    ~barbarian() override = default;

    void attack(troop &enemyTroop) override;

    void die() override;
};

#endif //OOP_BARBARIAN_HPP
