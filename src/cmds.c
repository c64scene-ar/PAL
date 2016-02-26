#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#include "common.h"
#include "game.h"
#include "cmds.h"

extern Room* current_room;

int parse_char_lowercase(char * str)
{
    int i;
    for( i = 0; i < strlen(str); i++ )
    {
        *(str + i) = tolower(*(str + i)); 
    }
}

#define S_EQUAL(tok, string, alias) ((strncmp(tok, string, sizeof(string)) == 0) \
                                 || (strncmp(tok, alias , sizeof(alias)) == 0))

/* returns true if a verb is detected */
int parse_verb(char * tok){

/* remember, all commands are 
   processed as lowercase */

   parse_char_lowercase(tok);

    #ifdef DEBUG
        printf("Parsing verb: %s\n", tok);
        printf("current_room is located at: %p\n", current_room);
    #endif 
        if(S_EQUAL(tok, "norte", "n"))
        {
            printf("Quieres ir al norte\n");
            if(current_room->exits[N] != NULL)
            {
                #ifdef DEBUG
                    printf("Movement points to: %p\n", current_room->exits[N]);
                #endif

                move_to(current_room->exits[N]);    
                return true;
            }
        }        
        if(S_EQUAL(tok, "sur", "s"))
        {
            printf("Quieres ir al sur\n");
            if(current_room->exits[S] != NULL)
            {
                #ifdef DEBUG
                    printf("Movement points to: %p\n", current_room->exits[S]);
                #endif
                move_to(current_room->exits[S]);    
                return true;
            }
        }        
        if(S_EQUAL(tok, "este", "e"))
        {
            printf("Quieres ir al este\n");
            if(current_room->exits[E] != NULL)
            {
                #ifdef DEBUG
                    printf("Movement points to: %p\n", current_room->exits[E]);
                #endif
                move_to(current_room->exits[E]);    
                return true;
            }
        }        
        if(S_EQUAL(tok, "oeste", "o"))
        {
            printf("Quieres ir al oeste\n");
            if(current_room->exits[W] != NULL)
            {
                #ifdef DEBUG
                    printf("Movement points to: %p\n", current_room->exits[W]);
                #endif
                move_to(current_room->exits[W]);    
                return true;
            }
        }

        printf("No entiendo a donde queres ir gato. Pa' ya no hay nada.\n");
        return false;
}

/* returns true if a object is detected */
int parse_object(char * tok) {

/* remember, all commands are 
   processed as lowercase */

    parse_char_lowercase(tok);

    #ifdef DEBUG
        printf("Parsing object: %s\n", tok);
    #endif
        /* if i didn-t encounter any object, then
           ill print "dont know what to do" */
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
                if(parse_object(tok)) { object = tok; };
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
}
