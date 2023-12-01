#include <iostream>
#include <limits>
#include "headers/player.hpp"

// Main menu of the game
// Testing the logic of the game
int main() {
    player mainPlayer = player(0, "You");
    player secondPlayer = player(0, "Alfred");

    // creating the buildings
    barracks mainBarracks = barracks(1000, 1);
    barracks secondBarracks = barracks(1000, 1);

    spellFactory mainSpellFactory = spellFactory(1000);
    spellFactory secondSpellFactory = spellFactory(1000);

    // adding troops and spells to the players
    std::unique_ptr<troop> newBarbarian = std::make_unique<barbarian>();
    std::unique_ptr<troop> newArcher = std::make_unique<archer>();
    std::unique_ptr<troop> newGiant = std::make_unique<giant>();

    // cloning the newBarbaran troop - demonstration purposes
    std::unique_ptr<troop> copyBarbarian = newBarbarian->clone();

    mainPlayer.addTroop(std::move(newBarbarian));
    mainPlayer.addTroop(std::move(newArcher));
    mainPlayer.addTroop(std::move(newGiant));

    std::unique_ptr<spell> newRage = std::make_unique<rage>();
    //std::unique_ptr<spell> newHeal = std::make_unique<heal>();
    mainPlayer.addSpell(std::move(newRage));
    //mainPlayer.addSpell(std::move(newHeal));

    std::unique_ptr<troop> newBarbarian2 = std::make_unique<barbarian>();
    std::unique_ptr<troop> newArcher2 = std::make_unique<archer>();
    std::unique_ptr<troop> newGiant2 = std::make_unique<giant>();
    secondPlayer.addTroop(std::move(newBarbarian2));
    secondPlayer.addTroop(std::move(newArcher2));
    secondPlayer.addTroop(std::move(newGiant2));

    std::unique_ptr<spell> newRage2 = std::make_unique<rage>();
    std::unique_ptr<spell> newHeal2 = std::make_unique<heal>();
    secondPlayer.addSpell(std::move(newRage2));
    secondPlayer.addSpell(std::move(newHeal2));

    // testing the attack method
    mainPlayer.attackEnemyTroop(secondPlayer, 0, 0);
    mainPlayer.attackEnemyTroop(secondPlayer, 1, 0);

    std::unique_ptr<spell> newHeal = std::make_unique<heal>();
    mainPlayer.addSpell(std::move(newHeal));

    // Cast heal on newBarbarian
    std::unique_ptr<spell> spellPtr = mainPlayer.getSpellAtIndex(1);
    std::unique_ptr<troop> troopPtr = mainPlayer.getTroopAtIndex(0);

    if (spellPtr && troopPtr) {
        spellPtr->cast(troopPtr);
        std::cout << "Healing successfully cast on newBarbarian!\n";
    } else {
        std::cout << "Failed to cast heal on newBarbarian.\n";
    }

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
