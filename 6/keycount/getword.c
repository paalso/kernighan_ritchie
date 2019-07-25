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
    if (c == EOF)
        return -1;
    
    *w = c;
    if (!isalpha(c)) {
        *++w = '\0';
        return word[0];
    }

    while(--lim > 0 && (isalpha((c = getch())) || isdigit(c)))
        *++w = c;
    *++w = '\0';
    ungetch(c);

    return word[0];
}
