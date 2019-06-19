#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <string.h> /* для strcmp */
#include <ctype.h> /* для tolower */
#include <math.h> /* для sin, exp, pow*/
#include <stdbool.h> /* для sin, exp, pow*/
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
    _Bool to_exit = false;
    double last;

    for (int i = 0; i < 26; ++i)
        vars[i] = 0;

    // while (true) {
    // while ((len = get_line(s)) > 0) {
    while ((len = get_line(s)) > -1) {
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
                    vars[index] = top();
                else
                    push(vars[index]);
                break;                

            case STACK_OP:
                if (!strcmp(word, "stack"))
                    print_stack();
                else if (!strcmp(word, "inv"))
                    inv();
                else if (!strcmp(word, "double"))
                    double_top();
                // else if (!strcmp(word, "top"))
                //     printf("\t%.8g\n", top());
                else if (!strcmp(word, "clear"))
                    clear();
                break;

            case COMMAND:
                if (!strcmp(word, "last"))
                    printf("last output: %g", last);
                else if (!strcmp(word, "quit") || !strcmp(word, "exit")) {
                    to_exit = true;
                    break;
                }
                break;

            default:
                printf("ошибка: неизвестная операция %s\n", word);
                break;
            }
        }

        last = top();
        printf("top: \n\t%.8g\n", last);
        if (to_exit) {
            printf("Exiting...\n");
            return 0;
        }
    }
    return 0;
}