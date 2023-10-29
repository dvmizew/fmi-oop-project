//
// Created by radud on 28.10.2023.
//
#ifndef OOP_SPELLS_H
#define OOP_SPELLS_H

class spell {
private:
    unsigned int brew_time{}, space_occupied{};
public:
    // init constructor
    spell(unsigned int brewTime, unsigned int spaceOccupied) : brew_time(brewTime), space_occupied(spaceOccupied) {}
    // copy constructor
    spell(const spell &obj): brew_time{obj.brew_time}, space_occupied{obj.brew_time} {}
    ~spell() = default;
    friend std::ostream& operator<<(std::ostream &, const spell&);
};

std::ostream &operator<<(std::ostream &out, const spell &obj) {
    out << obj.brew_time << " brewing time and occupies " << obj.space_occupied;
    return out;
}

#endif //OOP_SPELLS_H
