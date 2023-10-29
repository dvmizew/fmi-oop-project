//
// Created by radud on 28.10.2023.
//
#ifndef OOP_CONSTRUCTIONS_H
#define OOP_CONSTRUCTIONS_H
#include <vector>
#include <queue>
#include "troops.h"

class construction {
private:
    unsigned int hp{};
public:
    explicit construction(unsigned int hp) : hp(hp) {}
    ~construction() = default;
    friend std::ostream& operator<<(std::ostream &, const construction&);
};

std::ostream &operator<<(std::ostream &out, const construction &obj) {
    out << obj.hp << " HP";
    return out;
}

class barracks : construction {
private:
    unsigned int training_rate{};
    std::vector<troop> available_troops{};
    std::queue<troop> troops_in_queue{};
public:
    barracks(unsigned int hp, unsigned int trainingRate, std::vector<troop> availableTroops, std::queue<troop> troopsInQueue)
            : construction(hp), training_rate(trainingRate), available_troops(std::move(availableTroops)), troops_in_queue(std::move(troopsInQueue)) {}
    ~barracks() = default;
    friend std::ostream& operator<<(std::ostream &, const barracks&);
};

std::ostream &operator<<(std::ostream &out, const barracks &obj) {
    out << obj.training_rate << " training rate and it has " << obj.available_troops.size() << " available troops\n";
    return out;
}

#endif //OOP_CONSTRUCTIONS_H
