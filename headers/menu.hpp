//
// Created by radud on 08.01.2024.
//

#ifndef OOP_MENU_HPP
#define OOP_MENU_HPP


#include "player.hpp"

class menu {
public:
    static void displayMenu();

    static void createConstructions();

    static void getUserInput(player &mainPlayer, player &secondPlayer);
};


#endif //OOP_MENU_HPP
