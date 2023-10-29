//
// Created by radud on 28.10.2023.
//
#ifndef OOP_TROOPS_H
#define OOP_TROOPS_H

#include <string>

class troop {
private:
    unsigned int hp{}, damage{}, training_time{}, space_occupied{};
    bool damage_type{};
    std::string talk;
public:
    troop() = default;
    ~troop() = default;
    troop(unsigned int hp, unsigned int damage, unsigned int trainingTime, unsigned int spaceOcuppied, bool damageType)
            : hp(hp), damage(damage), training_time(trainingTime), space_occupied(spaceOcuppied),
              damage_type(damageType) {}

    friend std::ostream& operator<< (std::ostream &, const troop&);
};

std::ostream& operator<<(std::ostream& out, const troop &obj) {
    out << obj.hp << " HP, " << obj.damage << " damage, " << obj.training_time
        << " training time, and occupies " << obj.space_occupied << " spaces\n";
    if (obj.damage_type)
        out << "Melee damage\n";
    else
        out << "Ranged damage\n";
    return out;
}

#endif //OOP_TROOPS_H
