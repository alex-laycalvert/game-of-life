CFLAGS=-lncurses

gol:
	mkdir -p ./build
	$(CXX) $(CFLAGS) ./src/*.cpp -o ./build/gol
