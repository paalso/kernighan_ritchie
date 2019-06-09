#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include "calc.h"

#define MAXOP 100  /* макс. размер операнда или оператора */

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop (s)) != EOF) {
        switch (type) {
        case NUMBER:
            push (atof(s));
            break;
        case '+':
            push (pop() + pop());
            break;
        case '*':
            push (pop() * pop());
            break;
        case '-':
            op2 = pop();
            push (pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push (pop() / op2);
            else
                printf("ошибка: деление на нуль\n");
            break;
        // Упражнение 4-3. дополните программу- калькулятор таким образом, 
        // чтобы она "понимала" оператор получения остатка от деления (%)
        case '%':   
            op2 = pop();
            if (op2 != 0)
                push ((int) pop() % (int) op2);
            else
                printf("ошибка: деление на нуль\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
        }
    }
    return 0;
}