//
// Created by radud on 28.10.2023.
//
#ifndef OOP_SPELL_HPP
#define OOP_SPELL_HPP

#include <ostream>
#include <memory>
#include <iostream>
#include "troop.hpp"

class spell {
private:
    unsigned int brewTime{}, spaceOccupied{};
public:
    // init constructor
    spell(unsigned int brewTime, unsigned int spaceOccupied) : brewTime(brewTime), spaceOccupied(spaceOccupied) {}

    // copy constructor
    spell(const spell &obj) : brewTime{obj.brewTime}, spaceOccupied{obj.spaceOccupied} {}

    // Destructor
    virtual ~spell() = default;

    virtual void cast(std::unique_ptr<troop> &tr) = 0;

    virtual std::unique_ptr<spell> clone() = 0;

    // friend function for overloading <<
    friend std::ostream &operator<<(std::ostream &, const spell &);

    // operator= overloading for copying objects
    spell &operator=(const spell &obj);
};

// definition of the overloaded operator<<
std::ostream &operator<<(std::ostream &out, const spell &obj);

class heal : public spell {
public:
    heal() : spell(5, 1) {}

    ~heal() override = default;

    void cast(std::unique_ptr<troop> &tr) override;

    std::unique_ptr<spell> clone() override {
        return std::make_unique<heal>(*this);
    }
};

class rage : public spell {
public:
    rage() : spell(3, 1) {}

    ~rage() override = default;

    std::unique_ptr<spell> clone() override {
        return std::make_unique<rage>(*this);
    }

    void cast(std::unique_ptr<troop> &tr) override;
};

#endif //OOP_SPELL_HPP