//
// Created by radud on 26.11.2023.
//

#ifndef OOP_CUSTOM_EXCEPTIONS_H
#define OOP_CUSTOM_EXCEPTIONS_H

#include <exception>

class InvalidIndexException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class NullPointerException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class NoTroopsException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class NoSpellsException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override;
};

#endif //OOP_CUSTOM_EXCEPTIONS_H
