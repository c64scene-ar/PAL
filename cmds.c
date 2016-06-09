#include <string.h>
#include <stdio.h>
#include <conio.h>

#include "common.h"
#include "cmds.h"

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
    parse_action(verb, object);
}
