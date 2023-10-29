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
    construction() = default;
    ~construction() = default;
    explicit construction(unsigned int hp) : hp(hp) {}

    friend std::ostream& operator<<(std::ostream &, const construction&);
};

std::ostream &operator<<(std::ostream &out, const construction &obj) {
    out << obj.hp << " HP";
    return out;
}

class barracks : construction {
private:
    unsigned int training_rate;
    std::vector<troop> available_troops;
    std::queue<troop> troops_in_queue;
};

class wall : construction {

};

class town_hall : construction {

};

#endif //OOP_CONSTRUCTIONS_H
