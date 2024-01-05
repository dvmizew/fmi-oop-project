//
// Created by radud on 28.10.2023.
//
#ifndef OOP_CONSTRUCTION_HPP
#define OOP_CONSTRUCTION_HPP

#include <vector>
#include <queue>
#include <memory>
#include "troop.hpp"
#include "spell.hpp"

class construction {
private:
    unsigned int hp{};
public:
    // init constructor
    explicit construction(unsigned int hp) : hp(hp) {}

    // destructor
    ~construction() = default;

    construction &operator=(const construction &obj);

    friend std::ostream &operator<<(std::ostream &, const construction &);
};

// prototype of the overloaded operator<< for construction class
std::ostream &operator<<(std::ostream &out, const construction &obj);

#endif //OOP_CONSTRUCTION_HPP