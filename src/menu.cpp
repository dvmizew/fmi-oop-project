//
// Created by radud on 08.01.2024.
//

#include "../headers/menu.hpp"
#include "../headers/barracks.hpp"
#include "../headers/spellFactory.hpp"
#include <iostream>
#include <limits>

// Singleton instance getter
menu &menu::getInstance() {
    static menu instance;
    return instance;
}

void menu::displayMenu() {
    std::cout << "Press the key for the desired option and press ENTER:\n";
    std::cout << "0. EXIT\n";
    std::cout << "1. Add new player\n";
    std::cout << "2. View the current army\n";
    std::cout << "3. Create your army\n";
    std::cout << "4. Attack the enemy\n";
    std::cout << "5. View the player count\n";
    std::cout << "Your choice: ";
}

void menu::createBasePlayers(std::unique_ptr<player> &mainPlayer, std::unique_ptr<player> &secondPlayer) {
    mainPlayer = player::createPlayer(0, "Player 1");
    secondPlayer = player::createPlayer(0, "Player 2");
}

void menu::createConstructions() {
    barracks mainBarracks = barracks(1000, 1);
    barracks secondBarracks = barracks(1000, 1);
    spellFactory mainSpellFactory = spellFactory(1000);
    spellFactory secondSpellFactory = spellFactory(1000);
}

void menu::getUserInput(std::unique_ptr<player> &mainPlayer, std::unique_ptr<player> &secondPlayer) {
    // The user input is read as an unsigned int and then checked for validity
    unsigned int choice{};
    do {
        displayMenu();
        try {
            std::cin >> choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.\n");
            }
            if (choice > 5) {
                throw std::invalid_argument("Invalid choice. Please try again.\n");
            }

            // Switch case for the menu
            switch (choice) {
                case 0:
                    std::cout << "Exiting the program.\n";
                    break;
                case 1: {
                    player::createPlayer(0, "");
                    break;
                }
                case 2:
                    mainPlayer->viewCurrentArmy();
                    secondPlayer->viewCurrentArmy();
                    break;
                case 3:
                    mainPlayer->createArmy();
                    secondPlayer->createArmy();
                    break;
                case 4:
                    mainPlayer->attackPlayer(*secondPlayer);
                    break;
                case 5:
                    std::cout << "The player count is: " << player::getPlayerCount() << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Clearing cin's buffer before looping to prevent infinite loop
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);
}