#include <string.h>
#include <stdio.h>
#include <conio.h>

#include "game.h"
#include "common.h"

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

/* returns true if a verb is detected */
int parse_verb(char * tok){
    #ifdef DEBUG
        printf("Parsing verb: %s\n", tok);
    #endif

}

/* returns true if a object is detected */
int parse_object(char * tok) {
    #ifdef DEBUG
        printf("Parsing object: %s\n", tok);
    #endif
}

void parse_action(char * verb, char * object)
{

}

int parse_cmd(char * cmd)
{
    #define MAX_TOKENS 5
    char separator[2] = " ";
    char * tok = strtok(cmd, separator);
    byte token_count = 0;

    char * verb = NULL;
    char * object = NULL;

    while(tok != NULL)
    {
        #ifdef DEBUG
            printf("Tok: %s, tok_n: %d\n", tok, token_count);
        #endif 

        switch(token_count) {
            case 0: /* it should be a verb */
                if(parse_verb(tok)) { verb = tok; }
                break;
            case 1: /* it should be an article/object */
            case 2: /* it should be an article/object */
            case 3: /* it should be an article/object */
            case 4: /* it should be an article/object */
                if(parse_object(tok)) { object = tok };
                break;
            default:
                printf("No entiendo que quieres decir.\n");
                break;
        }

        tok = strtok(NULL, separator);

        token_count++;
        if(token_count >= MAX_TOKENS) 
        {
            printf("[Too complex]\n");
            return -1;    
        }
    }
    parse_action(verb, object);
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
