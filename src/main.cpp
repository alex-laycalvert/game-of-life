// alex-laycalvert
// https://github.com/alex-laycalvert/game-of-life

#include <ncurses.h>

#include "game_of_life.hpp"

int main(int argc, char **argv) {
    (void)argc, (void)argv;

    initscr();
    keypad(stdscr, true);
    noecho();
    raw();

    GOL *gol = GOL::getGOL();
    gol->loadFile("src/test.gol");
    gol->run(10);

    endwin();
    return 0;
}
