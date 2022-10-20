// alex-laycalvert
// https://github.com/alex-laycalvert/gol

#include "gol.hpp"

GOL *GOL::instance = 0;

GOL::GOL(){};

GOL *GOL::getGOL() {
    if (!GOL::instance) {
        GOL::instance = new GOL();
    }
    return GOL::instance;
}

void GOL::run(const int maxEvolutions, const int evolutionSpeed,
              const string cellCharacter) {
    for (int i = 0; i < maxEvolutions; i++) {
        printBoard(cellCharacter);
        sleep(evolutionSpeed);
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
        vector<int> boardRow;
        for (int i = 0; i < (int)line.size(); i++) {
            if (line.at(i) == ' ') {
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
        vector<int> boardRow;
        for (int i = 0; i < cols; i++) {
            boardRow.push_back(EMPTY);
        }
        board.push_back(boardRow);
    }
    boardRows = rows;
    boardCols = cols;
}

void GOL::evolve() {
    vector<vector<int> > newBoard(board);
    for (int i = 0; i < boardRows; i++) {
        for (int j = 0; j < boardCols; j++) {
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

void GOL::printBoard(const string cellCharacter) {
    for (int i = 0; i < boardRows; i++) {
        for (int j = 0; j < boardCols; j++) {
            string display = " ";
            if (board.at(i).at(j) == OCCUPIED) {
                display = cellCharacter;
            }
            mvprintw(i, j, "%s", display.c_str());
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

void GOL::sleep(const int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
