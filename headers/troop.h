//
// Created by radud on 28.10.2023.
//
#ifndef OOP_TROOP_H
#define OOP_TROOP_H

#include <string>

class troop {
private:
    unsigned int hp{}, damage{}, trainingTime{}, spaceOccupied{}, elixirCost{};
    bool damageType{};
    std::string name;
public:
    // init constructor
    troop(unsigned int hp, unsigned int damage, unsigned int trainingTime, unsigned int spaceOcuppied, bool damageType,
          unsigned int elixirCost, std::string& name)
            : hp(hp), damage(damage), trainingTime(trainingTime), spaceOccupied(spaceOcuppied),
              elixirCost(elixirCost), damageType(damageType), name(name) {
        std::cout << "Troop created!\n";
    }

    ~troop() = default;

    friend std::ostream &operator<<(std::ostream &, const troop &);

    // default functions for the troop
    // to be added
    void attack() {
        std::cout << "Attacking...\n";
    }

    void train() {
        std::cout << "Training...\n";
    }

    void die() {
        std::cout << "This troop is dead!\n";
        hp = 0;
    }
};

std::ostream &operator<<(std::ostream &out, const troop &obj) {
    out << obj.hp << " HP, " << obj.damage << " damage, " << obj.trainingTime
        << " training time, and occupies " << obj.spaceOccupied << " spaces and it costs " << obj.elixirCost;
    if (obj.damageType)
        out << "Melee damage\n";
    else
        out << "Ranged damage\n";
    return out;
}

#endif //OOP_TROOP_H