// Упражнение 5.10. Напишите программу expr, интерпретирующую обратную польскую запись 
// выражения, задаваемого командной строкой, в которой каждый оператор и 
// операнд представлены отдельным аргументом. Например,
// expr 2 3 4 + * 
// вычисляется так же, как выражение 2*(3+4).


// Баг с умножением
// Проблема заключается в том, что в режиме работы в командной строке
// символ '*' имеет, по-видимому, какой то предопределенный в ОС смысл, 
// что не позволяет его считывать и использовать как произволный символ
// Чтобы ОС корректно воспринимала 'звездочку', ее необходимо экранировать:
// ./expr 2 3 4 + \* 
// Или можно заменить на какой-л другой символ - напр. 'x'


#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <string.h> /* для strcmp */
#include "expr.h"

#define MAXLINE 100

// --- main -----------------------------------------
int main(int argc, char* argv[]) {

    char *token;
    int type;

    // while (--argc > 0) {
    while (token = *++argv) {
        // token = *++argv;
        type = getop(token);
        switch (type) {
            case NUMBER: push(atof(token));
                break;

            case MATH_OP:
                if (!strcmp(token, "+"))
                    push (pop() + pop());
                else if (!strcmp(token, "*"))
                    push (pop() * pop());
                else if (!strcmp(token, "-")) {
                    double op2 = pop();
                    push (pop() - op2);
                } else if (!strcmp(token, "/")) {
                    double op2 = pop();
                    if (op2 != 0.0)
                        push (pop() / op2);
                    else {
                        printf("error: zero division\n");
                        return 1;
                    }
                } else {
                    double op2 = pop();
                    if (op2 != 0)
                        push ((int) pop() % (int) op2);
                    else {
                        printf("error: zero division\n");
                        return 1;
                    }
                }
                break;

                default:
                    printf("error: unknown token - %s, numbers and math operations allowed only\n", token);
                    return 1;
        }
    }

    printf("%.8g\n", top());

    return 0;
}