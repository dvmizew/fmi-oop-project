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
    bool damageType{}; // true for melee, false for ranged
public:
    // init constructor
    troop(unsigned int hp, unsigned int damage, unsigned int trainingTime, unsigned int spaceOcuppied, bool damageType,
          unsigned int elixirCost)
            : hp(hp), damage(damage), trainingTime(trainingTime), spaceOccupied(spaceOcuppied),
              elixirCost(elixirCost), damageType(damageType) {
        std::cout << "Troop created!\n";
    }

    troop() = default;

    virtual ~troop() = default;

    troop &operator=(const troop &other);

    friend std::ostream &operator<<(std::ostream &, const troop &);

    void decreaseHP(unsigned int amount);

    void increaseHealth(unsigned int amount);

    // prototypes for virtual pure functions
    virtual void attack(troop &enemyTroop) = 0;

    virtual void die() = 0;
};

std::ostream &operator<<(std::ostream &out, const troop &obj);

class barbarian : public troop {
public:
    barbarian() : troop(100, BASE_DAMAGE_BARB, 0, 1, true, 50) {
        std::cout << "Barbarian created!\n";
    }

    ~barbarian() override = default;

    void attack(troop &enemyTroop) override;

    void die() override;
};

class archer : public troop {
public:
    archer() : troop(50, BASE_DAMAGE_ARCH, 0, 1, false, 100) {
        std::cout << "Archer created!\n";
    }

    ~archer() override = default;

    void attack(troop &enemyTroop) override;

    void die() override;
};

class giant : public troop {
public:
    giant() : troop(200, BASE_DAMAGE_GIANT, 0, 5, true, 500) {
        std::cout << "Giant created!\n";
    }

    ~giant() override = default;

    void attack(troop &enemyTroop) override;

    void die() override;
};

#endif //OOP_TROOP_HPP