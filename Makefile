PRG=game.prg
SRC=main.c text.s

all: $(PRG)

clean:
	rm -f *.o $(PRG) main.s

run: $(PRG)
	x64 +confirmexit $<

$(PRG): $(SRC)
	cl65 -O -t c64 -o $@ $^
