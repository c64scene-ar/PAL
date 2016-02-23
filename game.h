#ifndef __GAME_H__
#define __GAME_H__

#include <string.h>

#define true 1
#define false 0

#define MAX_LINE 40
#define MAX_EXITS 8

extern void start(void);

typedef enum { N = 0, NE = 1, E = 2, SE = 3, S = 4, SW = 5, W = 6, NW = 7 } Exit;

typedef struct {
    char* name;
    char* alias;
    char* description;
    void* exits[8];
    void** objects;
} Room;

typedef struct {
    char* name;
    char* alias;
    char** other_names;
    char* description;
} Object;


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

void __fastcall__ init_screen(void) {
    bgcolor(COLOR_BLACK);
    bordercolor(COLOR_BLACK);
    textcolor(COLOR_WHITE);
    cursor(1);
    clrscr();
}

void __fastcall__ main_loop(void) {
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
            printf("\nYou say '%s' but I don't understand.\n", buf);
        };
    }
}

#endif
