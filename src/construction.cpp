//
// Created by radud on 13.11.2023.
//

#include "../headers/construction.hpp"

// overloaded << operator for construction class
std::ostream &operator<<(std::ostream &out, const construction &obj) {
    out << obj.hp << " HP";
    return out;
}

// overloading the assignment operator
construction &construction::operator=(const construction &obj) {
    if (this != &obj) {
        this->hp = obj.hp;
    }
    return *this;
}