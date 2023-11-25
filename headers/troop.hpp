//
// Created by radud on 28.10.2023.
//
#ifndef OOP_TROOP_HPP
#define OOP_TROOP_HPP

#include <string>
#include <iostream>

#define BASE_DAMAGE 10 // minimum damage a troop can deal
#define BASE_DAMAGE_BARB 15
#define BASE_DAMAGE_ARCH 12
#define BASE_DAMAGE_GIANT 20

class troop {
private:
    unsigned int hp{}, damage = BASE_DAMAGE, trainingTime{}, spaceOccupied{}, elixirCost{};
    bool damageType{};
public:
    // init constructor
    troop(unsigned int hp, unsigned int damage, unsigned int trainingTime, unsigned int spaceOcuppied, bool damageType,
          unsigned int elixirCost)
            : hp(hp), damage(damage), trainingTime(trainingTime), spaceOccupied(spaceOcuppied),
              elixirCost(elixirCost), damageType(damageType) {
        std::cout << "Troop created!\n";
    }

    troop() = default;

    //~troop() = default;
    virtual ~troop() = default;

    friend std::ostream &operator<<(std::ostream &, const troop &);

    void decreaseHP(unsigned int amount);

    // prototypes for virtual pure functions
    virtual void attack(troop &enemyTroop) = 0;

    virtual void die() = 0;
};

std::ostream &operator<<(std::ostream &out, const troop &obj);

class barbarian : public troop {
public:
    void attack(troop &enemyTroop) override;

    void die() override;
};

class archer : public troop {
public:
    void attack(troop &enemyTroop) override;

    void die() override;
};

class giant : public troop {
public:
    void attack(troop &enemyTroop) override;

    void die() override;
};

#endif //OOP_TROOP_HPP