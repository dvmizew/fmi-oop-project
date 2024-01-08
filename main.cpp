#include "headers/player.hpp"
#include "headers/menu.hpp"

int main() {
    player mainPlayer = player::createPlayer(0, "You");
    player secondPlayer = player::createPlayer(0, "Alfred");

    menu::createConstructions(); // create the constructions

    // get the user input and display the menu
    menu::getUserInput(mainPlayer, secondPlayer);

    return 0;
}