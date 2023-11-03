//
// Created by radud on 28.10.2023.
//
#ifndef OOP_CONSTRUCTION_H
#define OOP_CONSTRUCTION_H

#include <vector>
#include <queue>
#include "troop.h"

class construction {
private:
    unsigned int hp{};
public:
    // init constructor
    explicit construction(unsigned int hp) : hp(hp) {}

    // destructor
    ~construction() = default;

    friend std::ostream &operator<<(std::ostream &, const construction &);
};

// definition of the overloaded operator<<
std::ostream &operator<<(std::ostream &out, const construction &obj) {
    out << obj.hp << " HP";
    return out;
}

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

// definition of the overloaded operator<<
std::ostream &operator<<(std::ostream &out, const barracks &obj) {
    out << obj.trainingRate << " training rate and it has " << obj.availableTroops.size() << " available troops\n";
    return out;
}

#endif //OOP_CONSTRUCTION_H
