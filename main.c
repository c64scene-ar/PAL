#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

extern const char text[];       /* In text.s */

#define MAX_LINE 40

void init_screen(void) {
    bgcolor(0);
    bordercolor(0);
    textcolor(1);
    cursor(1);
    clrscr();
}

int main(void) {
    char c;
    int i;
    char buf[MAX_LINE] = {};

    init_screen();

    printf("%s\n\n", text);

    // main loop
    while (1) {

        // input loop
        char posy;
        posy = wherey();

        i = 0;
        c = cgetc();
        while (c != '\n' && c != '\0') {
            if (c == '\b' && i > 0) {
                buf[i--] = '\0';
                cclearxy(i, posy, 1);
                gotox(i);
            } else {
                buf[i++] = c;
                cputc(c);
                if (i == MAX_LINE) break;
            }

            c = cgetc();
        };

        // handle input
        // ...

        // response
        // ...
        printf("\nYou say '%s' but I don't understand.\n\n", buf);
    }

    return EXIT_SUCCESS;
}
