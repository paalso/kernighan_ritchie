#include "sort_lines.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_line(char s[], int lim) {
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n' && --lim > 0) {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}


int readlines(char *lineptr[], int nlines) {
    int i = 0;
    int len;
    char line[MAXLEN];
    for (; len = get_line(line, MAXLEN) > 0; ++i) {
        char *tmp_line = malloc(sizeof(char) * (len + 1));
        if (! tmp_line || i == nlines)
            return -1;
        strcpy(tmp_line, line);
        lineptr[i] = tmp_line;
    }
    return i;
}


void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; ++i)
        printf("%s\n",lineptr[i]);
}