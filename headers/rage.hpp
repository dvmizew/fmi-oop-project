//
// Created by radud on 05.01.2024.
//

#ifndef OOP_RAGE_HPP
#define OOP_RAGE_HPP

#include "spell.hpp"

class rage : public spell {
public:
    rage() : spell(3, 1) {}

    ~rage() override = default;

    std::unique_ptr<spell> clone() override {
        return std::make_unique<rage>(*this);
    }

    void cast(std::unique_ptr<troop> &tr) override;
};


#endif //OOP_RAGE_HPP
