// Упражнение 5.7. Напишите новую версию readlines, которая запоминала бы строки в массиве, 
// определенном в main, а не запрашивала память посредством программы alloc. 
// Насколько быстрее эта программа?

// Откровенно говоря, не до конца понял, что имеется в виду
// Сделал следующее
// readlines таки не запрашивает память, а запоминет строки в массиве строк char lines[][MAXLEN]
// при этом, т.к. в дальнейшем обрабатывать, в т.ч. сортировать удобнее массив ссылок на строки,
// то при запоминании строк еще и запоминются ссылки на них в отдельном массиве char *lineptr[]


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


int readlines(char lines[][MAXLEN], char *lineptr[], int nlines) {
    int i = 0;
    int len;
    char line[MAXLEN];
    for (; len = get_line(line, MAXLEN) > 0; ++i) {
        if (i == nlines)
            return -1;
        strcpy(lines[i], line);
        lineptr[i] = lines[i];
    }
    return i;
}


void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; ++i)
        printf("%s\n",lineptr[i]);
}