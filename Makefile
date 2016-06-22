# Makefile adapted from sid-player SIDtracker64 prototype

.SILENT:

.PHONY: all dev dist clean test testdist gen_files

GAME = example

DEV_IMAGE = "bin/$(GAME)_dev.d64"
DIST_IMAGE = "bin/$(GAME).d64"

CC = cl65
CFLAGS = -g -Ln bin/$(GAME).sym -u __EXEHDR__ -t c64
C1541 = c1541
X64 = x64
EXOMIZER = exomizer

PRG = bin/$(GAME).prg
SYM = bin/$(GAME).sym
PACKED_PRG = bin/$(GAME)_exo.prg
SPEC = src/$(GAME).yaml
SRC = src/main.c src/game.c src/cmds.c
BUILD = src/build.rb

all: $(PRG)

# TODO: Use Exomizer correctly
dev: $(DEV_IMAGE)
dist: $(DIST_IMAGE)

$(DEV_IMAGE): $(PRG)
	$(C1541) -format "pvmadv,02" d64 $(DEV_IMAGE)
	$(C1541) $(DEV_IMAGE) -write $(PRG)
	$(C1541) $(DEV_IMAGE) -list

$(DIST_IMAGE): $(PRG)
	$(EXOMIZER) sfx sys -o $(PACKED_PRG) $(PRG)
	$(C1541) -format "pvmadv dist,02" d64 $(DIST_IMAGE)
	$(C1541) $(DIST_IMAGE) -write $(PACKED_PRG) "pvmadv $(GAME)"
	$(C1541) $(DIST_IMAGE) -list

$(PRG): $(SRC) $(wildcard src/*.h) gen_files
	$(CC) $(CFLAGS) -o $(PRG) $(SRC)

clean:
	rm -f bin/*.o $(PRG) $(DEV_IMAGE) $(DIST_IMAGE) $(SYM) src/main.s

test: $(DEV_IMAGE)
	x64 -moncommands $(SYM) +confirmexit $(DEV_IMAGE)

testdist: $(DIST_IMAGE)
	x64 -moncommands $(SYM) +confirmexit $(DIST_IMAGE)

gen_files: $(BUILD) $(SPEC) $(wildcard src/*.erb)
	$(BUILD) $(SPEC)
