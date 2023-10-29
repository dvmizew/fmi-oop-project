//
// Created by radud on 28.10.2023.
//
#ifndef OOP_TROOPS_H
#define OOP_TROOPS_H
#include <string>

class troop {
private:
    unsigned int hp{}, damage{}, training_time{}, space_occupied{}, elixir_cost{};
    bool damage_type{};
    std::string name;
public:
    troop() = default;
    ~troop() = default;
    troop(unsigned int hp, unsigned int damage, unsigned int trainingTime, unsigned int spaceOcuppied, bool damageType, unsigned int elixir_cost, std::string name)
            : hp(hp), damage(damage), training_time(trainingTime), space_occupied(spaceOcuppied),
              elixir_cost(elixir_cost), damage_type(damageType), name(std::move(name)) {
        std::cout << "Troop created!\n";
    }
    friend std::ostream& operator<< (std::ostream &, const troop&);

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

std::ostream& operator<<(std::ostream& out, const troop &obj) {
    out << obj.hp << " HP, " << obj.damage << " damage, " << obj.training_time
        << " training time, and occupies " << obj.space_occupied << " spaces and it costs " << obj.elixir_cost;
    if (obj.damage_type)
        out << "Melee damage\n";
    else
        out << "Ranged damage\n";
    return out;
}

#endif //OOP_TROOPS_H