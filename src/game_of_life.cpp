// alex-laycalvert
// https://github.com/alex-laycalvert/game-of-life

#include "game_of_life.hpp"

GOL *GOL::instance = 0;

GOL::GOL(){};

GOL *GOL::getGOL() {
    if (!GOL::instance) {
        GOL::instance = new GOL();
    }
    return GOL::instance;
}

void GOL::run() { run(DEFAULT_MAX_EVOLUTIONS); }

void GOL::run(const int maxEvolutions) {
    for (int i = 0; i < maxEvolutions; i++) {
        printBoard();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        evolve();
    }
}

void GOL::loadFile(const string filename) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << "\n";
        exit(1);
    }
    string line;
    while (getline(file, line)) {
        std::cout << "LINE: " << line << "\n";
        vector<char> boardRow;
        for (int i = 0; i < line.size(); i++) {
            if (line.at(i) == EMPTY) {
                boardRow.push_back(EMPTY);
            } else {
                boardRow.push_back(OCCUPIED);
            }
        }
        for (int i = line.size(); i < cols; i++) {
            boardRow.push_back(EMPTY);
        }
        board.push_back(boardRow);
    }
    for (int i = board.size(); i < rows; i++) {
        vector<char> boardRow;
        for (int i = 0; i < cols; i++) {
            boardRow.push_back(EMPTY);
        }
        board.push_back(boardRow);
    }
}

void GOL::evolve() {
    vector<vector<char>> newBoard(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(i).size(); j++) {
            int neighbors = getNeighbors(i, j);
            if (neighbors <= 1 || neighbors >= 4) {
                newBoard.at(i).at(j) = EMPTY;
            }
            if (neighbors == 3) {
                newBoard.at(i).at(j) = OCCUPIED;
            }
        }
    }
    board = newBoard;
}

void GOL::printBoard() {
    mvprintw(1, 1, "HELLO WORLD");
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(i).size(); j++) {
            mvprintw(i, j, "%d", board.at(i).at(j));
        }
    }
    refresh();
}

int GOL::getNeighbors(const int row, const int col) {
    int neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= boardRows || j < 0 || j >= boardCols ||
                (i == row && j == col)) {
                continue;
            }
            if (board.at(i).at(j) == OCCUPIED) {
                neighbors++;
            }
        }
    }
    return neighbors;
}
