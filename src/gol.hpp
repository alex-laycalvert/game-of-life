// alex-laycalvert
// https://github.com/alex-laycalvert/gol

#ifndef GOL_HPP_
#define GOL_HPP_

#define EMPTY 0
#define OCCUPIED 1
#define DEFAULT_MAX_EVOLUTIONS 5000
#define DEFAULT_EVOLUTION_SPEED 250
#define DEFAULT_CELL_CHARACTER "o"

#include <getopt.h>
#include <ncurses.h>
#include <signal.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <thread>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class GOL {
   public:
    static GOL *getGOL();
    void run(const int maxEvolutions, const int evolutionSpeed,
             const string cellCharacter);
    void loadFile(const string filename);

   private:
    GOL();
    ~GOL();
    static GOL *instance;
    int evolution;
    string file;
    vector<vector<int> > board;
    int boardRows;
    int boardCols;
    void evolve();
    void printBoard(const string cellCharacter);
    int getNeighbors(const int row, const int col);
    void sleep(const int milliseconds);
};

#endif // GOL_HPP_
