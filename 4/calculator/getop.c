#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define NUMBER '0'

/* getop: получает cледующий оператор или операнд */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;    /* не чиcло */
    i = 0;
    if (isdigit(c)) /* накапливаем целую чаcть */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c =='.') /* накапливаем дробную чаcть */
    while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}