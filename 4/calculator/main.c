#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <string.h> /* для strcmp */
#include <ctype.h> /* для tolower */
#include <math.h> /* для sin, exp, pow*/
#include "calc.h"

#define MAXOP 100  /* макс. размер операнда или оператора */

/* калькулятор с обратной польской записью */
int main()
{
    int type, index;
    int len = 0;
    int pos = 0;
    int vars[26];
    char s[MAXOP];
    char word[MAXOP];


    for (int i = 0; i < 26; ++i)
        vars[i] = 0;

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

            case MATH_FUN:
                if (!strcmp(word, "sin"))
                    push (sin(pop()));
                else if (!strcmp(word, "exp"))
                    push (exp(pop()));
                else if (!strcmp(word, "pow")) {
                    double op2 = pop();
                    push (pow(pop(), op2));
                }
                break;

            case VAR:
                index = tolower(word[0]) - 'a';
                if (vars[index] == 0)
                    vars[index] = take();
                else
                    push(vars[index]);
                break;                

            case STACK_OP:
                if (!strcmp(word, "prnlst"))
                    print_stack();
                break;

            default:
                printf("ошибка: неизвестная операция %s\n", word);
                break;
            }
        }

        printf("\t%.8g\n", pop());
    }
    return 0;
}