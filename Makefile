SPEC=example.yaml
PRG=game.prg

SRC=main.c game.c text.s cmds.c
BUILD=build.rb
ERB=*.erb

all: $(PRG)

clean:
	rm -f *.o $(PRG) main.s

run: $(PRG)
	x64 +confirmexit $<

gen_files: $(BUILD) $(SPEC) *.erb
	./$(BUILD) $(SPEC)

$(PRG): $(SRC) *.h gen_files
	cl65 -O -t c64 -o $@ $(SRC)
