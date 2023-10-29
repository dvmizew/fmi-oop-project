//
// Created by radud on 28.10.2023.
//
#ifndef OOP_CONSTRUCTIONS_H
#define OOP_CONSTRUCTIONS_H

class construction {
private:
    unsigned int hp;
public:
    construction() = default;
    ~construction() = default;
    construction(unsigned int hp) : hp(hp) {}

    friend std::ostream& operator<<(std::ostream &, construction&);
};

std::ostream &operator<<(std::ostream &out, construction &obj) {
    out << obj.hp << " HP";
    return out;
}

#endif //OOP_CONSTRUCTIONS_H
