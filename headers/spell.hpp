//
// Created by radud on 28.10.2023.
//
#ifndef OOP_SPELL_HPP
#define OOP_SPELL_HPP

#include <ostream>

class spell {
private:
    unsigned int brewTime{}, spaceOccupied{};
public:
    // init constructor
    spell(unsigned int brewTime, unsigned int spaceOccupied) : brewTime(brewTime), spaceOccupied(spaceOccupied) {}

    // copy constructor
    spell(const spell &obj) : brewTime{obj.brewTime}, spaceOccupied{obj.spaceOccupied} {}

    // Destructor
    ~spell() = default;

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

    virtual ~heal() = default;
};

class rage : public spell {
public:
    rage() : spell(3, 1) {}

    virtual ~rage() = default;
};

#endif //OOP_SPELL_HPP
