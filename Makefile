PRG=game.prg
SRC=main.c game.c text.s
INCLUDE=*.h

all: $(PRG)

clean:
	rm -f *.o $(PRG) main.s

run: $(PRG)
	x64 +confirmexit $<

$(PRG): $(SRC) $(INCLUDE)
	cl65 -O -t c64 -o $@ $(SRC)
