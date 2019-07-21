#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsort.h"

#define MAXLINES 5000 /* максимальное число строк */
char *lineptr[MAXLINES]; /* указатели на строки текста */

/* сортировка строк */
int main(int argc, char *argv[])
{
    int nlines;        /* количество прочитанных строк */
    int numeric = 0;   /* 1, если сорт. по числ. знач. */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        quicksort((void **) lineptr, 0, nlines-1,
          (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Bведено слишком много строк\n");
        return 1;
    }

    return 0;
}
