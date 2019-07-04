#include <stdio.h>
#include "expr.h"

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
        printf ("error: stack empty\n");
        return 0.0;
    }
}

/* top: копировать с вершины стека*/
double top(void)
{
    if (sp > 0)
        return val[sp - 1];
    else {
        printf ("stack empty\n");
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

/* inv: поменять местами два элемента с вершины стека с вершины стека*/
void inv(void)
{
    if (sp > 1)
    {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
}

/* double_top: дублирует верхний элемент стека*/
double double_top(void)
{
    if (sp > 0)
    {
        ++sp;
        val[sp - 1] = val[sp - 2];
        return val[sp - 1];
    }
    else {
        printf ("error: stack empty\n");
    return 0.0;
    }
}

/* clear: очищает стек*/
void clear(void)
{
    sp = 0;
}