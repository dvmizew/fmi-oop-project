#include "headers/player.hpp"
#include "headers/menu.hpp"

int main() {
    menu &mainMenu = menu::getInstance();

    player player1(0, ""), player2(0, "");

    mainMenu.createBasePlayers(player1, player2);
    mainMenu.createConstructions();

    mainMenu.getUserInput(player1, player2);
    return 0;
}