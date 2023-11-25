//
// Created by radud on 28.10.2023.
//
#ifndef OOP_CONSTRUCTION_HPP
#define OOP_CONSTRUCTION_HPP

#include <vector>
#include <queue>
#include "troop.hpp"

class construction {
private:
    unsigned int hp{};
public:
    // init constructor
    explicit construction(unsigned int hp) : hp(hp) {}

    // destructor
    ~construction() = default;

    construction& operator=(const construction& obj);

    friend std::ostream &operator<<(std::ostream &, const construction &);
};

// prototype of the overloaded operator<< for construction class
std::ostream &operator<<(std::ostream &out, const construction &obj);

// class for the barracks construction
class barracks : construction {
private:
    unsigned int trainingRate{};
    std::vector<troop> availableTroops{};
    std::queue<troop> troopsInQueue{};
public:
    barracks(unsigned int hp, unsigned int trainingRate, std::vector<troop> availableTroops,
             std::queue<troop> troopsInQueue)
            : construction(hp), trainingRate(trainingRate), availableTroops(std::move(availableTroops)),
              troopsInQueue(std::move(troopsInQueue)) {}

    ~barracks() = default;

    // friend function for overloading <<
    friend std::ostream &operator<<(std::ostream &, const barracks &);
};

// prototype of the overloaded operator<< for barracks class
std::ostream &operator<<(std::ostream &out, const barracks &obj);

#endif //OOP_CONSTRUCTION_HPP
