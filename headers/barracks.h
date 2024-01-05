//
// Created by radud on 05.01.2024.
//

#ifndef OOP_BARRACKS_H
#define OOP_BARRACKS_H

#include "construction.hpp"

// class for the barracks construction
class barracks : public construction {
private:
    unsigned int trainingRate{};
    std::vector<std::unique_ptr<troop>> availableTroops{};
    std::queue<std::unique_ptr<troop>> troopsInQueue{};
public:
    barracks(unsigned int hp, unsigned int trainingRate)
            : construction(hp), trainingRate(trainingRate) {}

    ~barracks() = default;

    // friend function for overloading <<
    friend std::ostream &operator<<(std::ostream &, const barracks &);
};

// prototype of the overloaded operator<< for barracks class
std::ostream &operator<<(std::ostream &out, const barracks &obj);

#endif //OOP_BARRACKS_H
