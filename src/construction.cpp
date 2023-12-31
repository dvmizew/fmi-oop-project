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
    // checking if the object is not the same as the one we are assigning to
    if (this != &obj) {
        this->hp = obj.hp;
    }
    return *this;
}