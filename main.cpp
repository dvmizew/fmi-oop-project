#include "headers/player.hpp"
#include "headers/menu.hpp"

int main() {
    player mainPlayer = player::createPlayer(0, "You");
    player secondPlayer = player::createPlayer(0, "Alfred");

    menu::createConstructions();

    menu::getUserInput(mainPlayer, secondPlayer);

    return 0;
}
