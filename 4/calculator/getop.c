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
    if (!isdigit(c) && c != '.' && c != '-')    // Упражнение 4.3. ...дополните программу - 
        return c;    /* не чиcло */             // калькулятор таким образом, чтобы она "понимала" 
    i = 0;                                      // оператор получения остатка от деления (%) и отрицательные числа
    if (c == '-' && i > 0)
            return c;   /* не чиcло */
    if (isdigit(c) || c == '-') /* накапливаем целую чаcть */
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