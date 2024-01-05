//
// Created by radud on 01.12.2023.
//

#include "../headers/custom_exceptions.hpp"

const char *InvalidIndexException::what() const noexcept {
    return "Invalid index!\n";
}

const char *NullPointerException::what() const noexcept {
    return "Null pointer!\n";
}

const char *NoTroopsException::what() const noexcept {
    return "No troops! Create an army first!\n";
}

const char *NoSpellsException::what() const noexcept {
    return "No spells! Create an army first!\n";
}