UNAME := $(shell uname)
CFLAGS=-lncurses

ifeq ($(UNAME), Darwin)
	PREFIX=/usr/local
endif

ifeq ($(UNAME), Linux)
	PREFIX=/usr
endif

gol:
	mkdir -p ./bin
	$(CXX) $(CFLAGS) ./src/*.cpp -o ./bin/gol
.PHONY: install
install: gol
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp bin/gol $(DESTDIR)$(PREFIX)/bin/gol
.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/gol
