#include <iostream>
#include <limits>
#include "headers/player.hpp"

// Main menu of the game
int main() {
    player mainPlayer = player(0, "You");
    player secondPlayer = player(0, "Alfred");

    // creating the buildings
    barracks mainBarracks = barracks(1000, 1);
    barracks secondBarracks = barracks(1000, 1);

    spellFactory mainSpellFactory = spellFactory(1000);
    spellFactory secondSpellFactory = spellFactory(1000);

    // a "infinitely" running loop for the main menu
    unsigned int choice{};
    do {
        std::cout << "Main menu\n\n";
        std::cout << "Press the key for the desired option and press ENTER:\n";
        std::cout << "0. EXIT\n";
        std::cout << "1. View the current army\n";
        std::cout << "2. Create your army\n";
        std::cout << "3. Attack the enemy\n";
        std::cout << "Your choice: ";
        try {
            std::cin >> choice;
            if (choice > 3)
                throw std::invalid_argument("Invalid choice. Please try again.\n");
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear(); // for clearing the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // for clearing the buffer
        }

        switch (choice) {
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            case 1:
                mainPlayer.viewCurrentArmy();
                secondPlayer.viewCurrentArmy();
                break;
            case 2:
                // a function to create the army for the player
                mainPlayer.createArmy();
                secondPlayer.createArmy();
                break;
            case 3:
                // a function to test the attack method
                mainPlayer.attackPlayer(secondPlayer);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
