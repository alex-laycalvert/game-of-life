// alex-laycalvert
// https://github.com/alex-laycalvert/game-of-life

#ifndef GAME_OF_LIFE_HPP_
#define GAME_OF_LIFE_HPP_

#define EMPTY ' '
#define OCCUPIED 'o'
#define DEFAULT_MAX_EVOLUTIONS 5000

#include <ncurses.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class GOL {
   public:
    static GOL *getGOL();
    void run();
    void run(const int maxEvolutions);
    void loadFile(const string filename);

   private:
    GOL();
    ~GOL();
    static GOL *instance;
    int evolution;
    string file;
    vector<vector<char>> board;
    int boardRows;
    int boardCols;
    void evolve();
    void printBoard();
    int getNeighbors(const int row, const int col);
};

#endif // GAME_OF_LIFE_HPP_
