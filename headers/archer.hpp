//
// Created by radud on 05.01.2024.
//

#ifndef OOP_ARCHER_HPP
#define OOP_ARCHER_HPP

#include "troop.hpp"

class archer : public troop {
public:
    archer() : troop(50, BASE_DAMAGE_ARCH, 0, 1, false, 100, 3) {
        std::cout << "Archer created!\n";
    }

    std::unique_ptr<troop> clone() override {
        return std::make_unique<archer>(*this);
    }

    ~archer() override = default;

    void attack(troop &enemyTroop) override;

    void die() override;
};


#endif //OOP_ARCHER_HPP
