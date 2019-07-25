#include <ctype.h>
#include <stdio.h>

int getch();
void ungetch(int);


int getword(char *word, int lim) {
    char *w = word;
    int c;

    // while ((c = getch()) == ' ' || c == '\t')
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++) {
        if (! isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}
