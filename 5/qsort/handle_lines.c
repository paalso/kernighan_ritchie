#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 100


int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i] = '\0';
    return i;
}


/* readlines: чтение строк */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len + 1)) == NULL)
            return -1; 
        else {
            line[len] = '\0'; /* убираем символ \n */
            strcpy(p, line);
            lineptr[nlines++] = p;
        } 
    return nlines;
}

/* writelines: печать строк */
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; ++i)
        printf("%s\n",lineptr[i]);
}
