# alex-laycalvert
# https://github.com/alex-laycalvert/slacker

CFLAGS=-std=c++20 -lncurses

game-of-life:
	mkdir -p ./build
	$(CXX) $(CFLAGS) src/*.cpp -o ./build/gol
dev:
	mkdir -p ./build
	$(CXX) $(CFLAGS) -Wall -Wextra src/*.cpp -o ./build/gol.dev
