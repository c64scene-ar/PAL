#include <string.h>
#include <stdio.h>
#include <conio.h>

#include "game.h"
#include "common.h"
#include "cmds.h"

#define MAX_LINE 40
#define MAX_EXITS 8

#define DEBUG

Room* current_room;


void where_am_I(void) {
    char* prefix = current_room->prefix;
    if (prefix == NULL) {
        printf("Estas en %s.\n", current_room->name);
    } else {
        printf("Estas en %s %s.\n", current_room->prefix, current_room->name);
    }
    printf("\n");
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

        /*if (stricmp(buf, "mirar") == 0) {
            look();
        } else if (stricmp(buf, "donde estoy") == 0) {
            where_am_I();
        } else {
            printf("[Verbo o comando desconocido]\n", buf);
        };*/
        parse_cmd(buf);
    }
}
