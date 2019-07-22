// Упражнение 5.14. Модифицируйте программу сортировки, чтобы она реагировала 
// на параметр -r, указывающий, что объекты нужно сортировать в обратном порядке, 
// т. е. в порядке убывания. Обеспечьте, чтобы -r работал и вместе с -n.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsort.h"

#define EXIT_ERR { fprintf(stderr, "Usage: find [-n] [-x] pattern\n"); return 1;}

#define MAXLINES 5000 /* максимальное число строк */
char *lineptr[MAXLINES]; /* указатели на строки текста */

/* сортировка строк */
int main(int argc, char *argv[])
{
    int nlines;        /* количество прочитанных строк */
    int numeric = 0;   /* 1, если сорт. по числовому значению */
    int reverse = 0;   /* 1, если сорт. в порядке убывания */

    // if (argc > 1 && strcmp(argv[1], "-n") == 0)
    //     numeric = 1;

    // обработка ввода: чтение пераметров
    char c;
    while(--argc && (*++argv)[0] == '-') {
        while(c = *++argv[0]) {
            switch(c) {
                case 'n': numeric = 1; break;   // сортировка в числовом порядке
                case 'r': reverse = 1; break;   // сортировка в порядке убывания
                default: 
                    printf("Incorrect parameter %c\n", c);
                    EXIT_ERR
            } 
        }
    } 

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        quicksort((void **) lineptr, 0, nlines-1,
          (int (*)(void*,void*))(numeric ? numcmp : strcmp), 1 - reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Bведено слишком много строк\n");
        return 1;
    }

    return 0;
}
