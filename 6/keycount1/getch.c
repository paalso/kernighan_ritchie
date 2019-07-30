#include <stdio.h>

#define BUFSIZE     100

int buffer[BUFSIZE];
int bufcounter = 0;


int getch() {
    return bufcounter > 0 ? buffer[--bufcounter] : getchar();
}


void ungetch(int c) {
    if (bufcounter < BUFSIZE)
        buffer[bufcounter++] = c;
    else
        fprintf(stderr, "Error: buffer overflow\n");
}
