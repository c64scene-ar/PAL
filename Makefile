.SILENT:

.PHONY: all clean run gen_files

X64=x64
CC=cl65
CFLAGS=-O -t c64

GAME=example

PRG=bin/$(GAME).prg
SPEC=src/$(GAME).yaml
SRC=src/main.c src/game.c
BUILD=src/build.rb

all: $(PRG)

clean:
	rm -f bin/*.o $(PRG) src/main.s

run: $(PRG)
	x64 +confirmexit $(PRG)

gen_files: $(BUILD) $(SPEC) src/*.erb
	./$(BUILD) $(SPEC)

$(PRG): $(SRC) src/*.h gen_files
	$(CC) $(CFLAGS) -o $(PRG) $(SRC)
