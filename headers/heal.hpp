//
// Created by radud on 05.01.2024.
//

#ifndef OOP_HEAL_HPP
#define OOP_HEAL_HPP

#include "spell.hpp"

class heal : public spell {
public:
    heal() : spell(5, 1) {}

    ~heal() override = default;

    void cast(std::unique_ptr<troop> &tr) override;

    std::unique_ptr<spell> clone() override {
        return std::make_unique<heal>(*this);
    }
};

#endif //OOP_HEAL_HPP
