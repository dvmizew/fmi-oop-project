//
// Created by radud on 26.11.2023.
//

#ifndef OOP_CUSTOM_EXCEPTIONS_H
#define OOP_CUSTOM_EXCEPTIONS_H

#include <exception>

class InvalidIndexException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Invalid index!\n";
    }
};

class NullPointerException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Null pointer!\n";
    }
};

#endif //OOP_CUSTOM_EXCEPTIONS_H
