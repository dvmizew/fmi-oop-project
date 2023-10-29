#include <iostream>
#include "headers/player.h"

int main() {
    // Main menu
    player gamer = player(0, 0, 0, 0, 0, "Gamer", {}, {});
    unsigned int choice;
    do {
        std::cout << "Main menu\n\n";
        std::cout << "Press the key for the desired option and press ENTER:\n";
        std::cout << "0. EXIT\n";
        std::cout << "1. View the current army\n";
        std::cout << "2. Look for battle\n";
        std::cout << "3. Check your current stats\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            case 1:
                gamer.viewCurrentArmy();
                break;
            case 2:
                player::lookForBattle();
                break;
            case 3:
                std::cout << gamer;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
