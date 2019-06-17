#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <string.h> /* для atof() */
#include "calc.h"

#define MAXOP 100  /* макс. размер операнда или оператора */

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    int len = 0;
    int pos = 0;
    char s[MAXOP];
    char word[MAXOP];

    //aa bb

    while ((len = get_line(s)) > 0) {
        int position = 0;
        while(position < len) {
         
            position = get_word(position, s, word);
            type = getop(word);

            switch (type) {
            
            case NUMBER:
                push (atof(word));
                break;

            case MATH_OP:
                if (!strcmp(word, "+"))
                    push (pop() + pop());
                else if (!strcmp(word, "*"))
                    push (pop() * pop());
                else if (!strcmp(word, "-")) {
                    double op2 = pop();
                    push (pop() - op2);
                } else if (!strcmp(word, "/")) {
                    double op2 = pop();
                    if (op2 != 0.0)
                        push (pop() / op2);
                    else
                        printf("ошибка: деление на нуль\n");
                } else {
                    double op2 = pop();
                    if (op2 != 0)
                        push ((int) pop() % (int) op2);
                    else
                        printf("ошибка: деление на нуль\n");
                }
                break;

            default:
                printf("ошибка: неизвестная операция %s\n", s);
                break;
            }

            printf("\t%.8g\n", pop());

        }
    }
    return 0;
}