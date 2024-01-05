//
// Created by radud on 05.01.2024.
//

#ifndef OOP_GIANT_HPP
#define OOP_GIANT_HPP


#include "troop.hpp"

class giant : public troop {
public:
    giant() : troop(200, BASE_DAMAGE_GIANT, 0, 5, true, 500, 1) {
        std::cout << "Giant created!\n";
    }

    std::unique_ptr<troop> clone() override {
        return std::make_unique<giant>(*this);
    }

    ~giant() override = default;

    void attack(troop &enemyTroop) override;

    void die() override;
};


#endif //OOP_GIANT_HPP
