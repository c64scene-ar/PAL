#include <string.h>
#include <stdio.h>
#include <conio.h>

#include "game.h"
#include "common.h"

#define MAX_LINE 40
#define MAX_EXITS 8

Room* current_room;


void where_am_I(void) {
    printf("You are in a %s.\n\n", current_room->name);
}

void look(void) {
    printf(current_room->description);
    printf("\n");
}

void move_to(Room* room) {
    current_room = room;

    where_am_I();
    look();
}

void init_screen(void) {
    bgcolor(COLOR_BLACK);
    bordercolor(COLOR_BLACK);
    textcolor(COLOR_WHITE);
    cursor(1);
    clrscr();
}

void main_loop(void) {
    char buf[MAX_LINE] = {};

    init_screen();
    start();

    while (true) {
        printf("\n> ");
        gets(buf);

        if (stricmp(buf, "look") == 0) {
            look();
        } else if (stricmp(buf, "where am i") == 0) {
            where_am_I();
        } else {
            printf("You say '%s' but I don't understand.\n", buf);
        };
    }
}
