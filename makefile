PREFIX=/usr
CFLAGS=-lncurses

all:
gol:
	mkdir -p ./bin
	$(CXX) $(CFLAGS) ./src/*.cpp -o ./bin/gol
install: gol
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp bin/gol $(DESTDIR)$(PREFIX)/bin/gol
clean:
	rm -f $(DESTDIR)$(PREFIX)/bin/gol
