//
// Created by radud on 28.10.2023.
//
#ifndef OOP_TROOP_HPP
#define OOP_TROOP_HPP

#include <string>
#include <iostream>

class troop {
private:
    unsigned int hp{}, damage{}, trainingTime{}, spaceOccupied{}, elixirCost{};
    bool damageType{};
    std::string name;
public:
    // init constructor
    troop(unsigned int hp, unsigned int damage, unsigned int trainingTime, unsigned int spaceOcuppied, bool damageType,
          unsigned int elixirCost, std::string &name)
            : hp(hp), damage(damage), trainingTime(trainingTime), spaceOccupied(spaceOcuppied),
              elixirCost(elixirCost), damageType(damageType), name(name) {
        std::cout << "Troop created!\n";
    }

    ~troop() = default;

    friend std::ostream &operator<<(std::ostream &, const troop &);

    // prototypes
    [[maybe_unused]] static void attack();

    [[maybe_unused]] static void train();

    [[maybe_unused]] void die();
};

std::ostream &operator<<(std::ostream &out, const troop &obj);

#endif //OOP_TROOP_HPP