#include <stdio.h>
#include "calc.h"

#define MAXVAL 100  /* максимальная глубина стека */

int sp = 0;         /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек */

/* push: положить значение f в стек */ 
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

/* pop: взять с вершины стека и выдать в качестве результата */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf ("ошибка: стек пуст\n");
    return 0.0;
    }
}

/* take: копировать с вершины стека*/
double take(void)
{
    if (sp > 0)
        return val[sp];
    else {
        printf ("ошибка: стек пуст\n");
    return 0.0;
    }
}

/* print_stack: копировать с вершины стека*/
void print_stack(void)
{
    printf("\nCurrent stack: ");
    for (int i = 0; i < sp; ++i)
    {
        printf("%g ",val[i]);
    }
    printf("\n");
}