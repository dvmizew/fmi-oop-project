//
// Created by radud on 08.01.2024.
//

#ifndef OOP_MENU_HPP
#define OOP_MENU_HPP

#include "player.hpp"

// Singleton class for the menu
class menu {
public:
    static menu &getInstance(); // Singleton instance getter

    static void displayMenu();

    static void createConstructions();

    static void createBasePlayers(std::unique_ptr<player> &mainPlayer, std::unique_ptr<player> &secondPlayer);

    static void getUserInput(std::unique_ptr<player> &mainPlayer, std::unique_ptr<player> &secondPlayer);

    menu(const menu &) = delete; // Delete copy constructor
    menu &operator=(const menu &) = delete; // Delete assignment operator

private:
    menu() = default; // Private constructor to prevent direct instantiation
    ~menu() = default; // Private destructor to prevent deletion
};

#endif //OOP_MENU_HPP