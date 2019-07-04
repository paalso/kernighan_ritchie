#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */

int get_line(char buf[]) {
    int c, i = 0;

    while((c = getchar()) != EOF && i < BUFSIZE - 1) {
        if (c == '\n')
            break;
        buf[i++] = c;
    }
    buf[i] = '\0';

    return i;
}


int get_word(int pos, char buf[], char word[]) {
    int i = pos;
    int j = 0;
    for (; isblank(buf[i]); ++i)
        ;
    for (; ! isblank(buf[i]) && buf[i] != '\0'; ++i, ++j)
        word[j] = buf[i];
    word[j] = '\0';
    return i;
}