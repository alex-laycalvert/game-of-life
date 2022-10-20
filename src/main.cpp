// alex-laycalvert
// https://github.com/alex-laycalvert/game-of-life

#include "gol.hpp"

using std::stoi;

void signalHandler(int signum) {
    (void)signum;
    endwin();
    exit(0);
}

void usage(string name) {
    std::cout << "usage: " << name << " [options]\n\n";
    std::cout << "author: alex-laycalvert\n\n";
    std::cout << "A C++ implementation of John Conway's Game of Life\n";
    std::cout << "https://github.com/alex-laycalvert/game-of-life\n\n";
    std::cout << "options:\n";
    std::cout << "\t-h\t\tdisplay this menu\n";
    std::cout << "\t-f <filename>\tfile to read the board state from\n";
    std::cout << "\t-n <number>\tnumber of evolutions to run (default: 5000)\n";
    std::cout << "\t-s <number>\tspeed in milliseconds of each evolution "
                 "(default: 250)\n";
    std::cout << "\t-c <character>\tcharacter to print for occupied cells "
                 "(default: 'o')\n";
}

int main(int argc, char **argv) {
    int maxEvolutions = DEFAULT_MAX_EVOLUTIONS;
    int evolutionSpeed = DEFAULT_EVOLUTION_SPEED;
    string cellCharacter = DEFAULT_CELL_CHARACTER;
    string filename = "";

    signal(SIGINT, signalHandler);

    int c;
    while ((c = getopt(argc, argv, "hn:s:f:c:")) != -1) {
        switch (c) {
            case 'h':
                usage(argv[0]);
                exit(0);
                break;
            case 'n':
                maxEvolutions = stoi(optarg);
                break;
            case 's':
                evolutionSpeed = stoi(optarg);
                break;
            case 'f':
                filename = optarg;
                break;
            case 'c':
                cellCharacter = optarg;
                break;
            case '?':
                usage(argv[0]);
                exit(1);
                break;
            default:
                usage(argv[0]);
                exit(1);
                break;
                break;
        }
    }

    if (filename.size() <= 0) {
        std::cerr << "Please provide a file with -f <filename>\n";
        exit(1);
    }

    setlocale(LC_ALL, "");
    initscr();
    keypad(stdscr, true);
    noecho();
    raw();
    cbreak();
    curs_set(0);

    GOL *gol = GOL::getGOL();
    gol->loadFile(filename);
    gol->run(maxEvolutions, evolutionSpeed, cellCharacter);

    endwin();
    return 0;
}
