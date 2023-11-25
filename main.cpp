#include <iostream>
#include <vector>
#include "headers/player.hpp"

// Main menu of the game
// Testing the logic of the game
int main() {
    // First player
    player mainPlayer = player(0, 0, 0, 0, 0, "You", {}, {});

    std::unique_ptr<troop> newBarbarian = std::make_unique<barbarian>();
    std::unique_ptr<troop> newArcher = std::make_unique<archer>();
    std::unique_ptr<troop> newGiant = std::make_unique<giant>();
    mainPlayer.recruitTroop(std::move(newBarbarian));
    mainPlayer.recruitTroop(std::move(newArcher));
    mainPlayer.recruitTroop(std::move(newGiant));

    // brewing some spells for the main player - TEST
    std::unique_ptr<heal> newHealSpell = std::make_unique<heal>();
    std::unique_ptr<rage> newRageSpell = std::make_unique<rage>();
    mainPlayer.brewSpell(std::move(newHealSpell));
    mainPlayer.brewSpell(std::move(newRageSpell));

    // Second player
    player secondPlayer = player(0, 0, 0, 0, 0, "Alfred", {}, {});
    std::unique_ptr<troop> newSecondBarbarian = std::make_unique<barbarian>();
    std::unique_ptr<troop> newSecondArcher = std::make_unique<archer>();
    std::unique_ptr<troop> newSecondGiant = std::make_unique<giant>();
    secondPlayer.recruitTroop(std::move(newSecondBarbarian));
    secondPlayer.recruitTroop(std::move(newSecondArcher));
    secondPlayer.recruitTroop(std::move(newSecondGiant));

    // brewing some spells for the second player - TEST
    std::unique_ptr<heal> newSecondHealSpell = std::make_unique<heal>();
    std::unique_ptr<rage> newSecondRageSpell = std::make_unique<rage>();
    secondPlayer.brewSpell(std::move(newSecondHealSpell));
    secondPlayer.brewSpell(std::move(newSecondRageSpell));

    // Testing the attack function
    mainPlayer.attackEnemyTroop(secondPlayer, 0, 0);
    mainPlayer.attackEnemyTroop(secondPlayer, 1, 0);
    mainPlayer.attackEnemyTroop(secondPlayer, 2, 0);

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
                secondPlayer.viewCurrentArmy();
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
