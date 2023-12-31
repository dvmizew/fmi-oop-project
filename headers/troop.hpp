//
// Created by radud on 28.10.2023.
//
#ifndef OOP_TROOP_HPP
#define OOP_TROOP_HPP

#include <string>
#include <iostream>
#include <memory>

#define BASE_DAMAGE 10 // minimum damage a troop can deal
#define BASE_DAMAGE_BARB 15
#define BASE_DAMAGE_ARCH 12
#define BASE_DAMAGE_GIANT 20

class troop {
private:
    unsigned int hp{}, damage = BASE_DAMAGE, trainingTime{}, spaceOccupied{}, elixirCost{}, speed{};
    bool damageType{}; // true for melee, false for ranged
public:
    // init constructor
    troop(unsigned int hp, unsigned int damage, unsigned int trainingTime, unsigned int spaceOcuppied, bool damageType,
          unsigned int elixirCost, unsigned int _speed)
            : hp(hp), damage(damage), trainingTime(trainingTime), spaceOccupied(spaceOcuppied),
              elixirCost(elixirCost), speed(_speed), damageType(damageType) {
        std::cout << "Troop created!\n";
    }

    // copy constructor
    troop(const troop &other) {
        hp = other.hp;
        damage = other.damage;
        trainingTime = other.trainingTime;
        spaceOccupied = other.spaceOccupied;
        elixirCost = other.elixirCost;
        damageType = other.damageType;
    }

    virtual std::unique_ptr<troop> clone() = 0;

    troop() = default;

    virtual ~troop() = default;

    troop &operator=(const troop &other);

    friend std::ostream &operator<<(std::ostream &, const troop &);

    void decreaseHP(unsigned int amount);

    void increaseHealth(unsigned int amount);

    void increaseSpeed(unsigned int amount);

    // prototypes for virtual pure functions
    virtual void attack(troop &enemyTroop) = 0;

    virtual void die() = 0;
};

std::ostream &operator<<(std::ostream &out, const troop &obj);

#endif //OOP_TROOP_HPP