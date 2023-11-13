#include <iostream>
#include <vector>
#include "headers/player.hpp"

int main() {
    // Main menu
    player mainPlayer = player(0, 0, 0, 0, 0, "You", {}, {});
    std::vector<player> players{};
    // a "infinitely" running loop for the main menu
    unsigned int choice{};
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
                mainPlayer.viewCurrentArmy();
                break;
            case 2:
                player::lookForBattle();
                break;
            case 3:
                std::cout << mainPlayer;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
