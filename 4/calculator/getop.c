#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "calc.h"


char math_operations[][1] = {"+", "-", "*", "/", "%"};
int math_operations_len = 5;

char math_functions[][3] = {"sin", "exp", "pow"};
int math_functions_len = 3;

char stack_operations[][8] = {"top", "double", "inv", "prnlst"};
int stack_functions_len = 4;

_Bool is_number(char s[]) {
    int i = 0;
    int digits = 0;
    int c;

    if (s[0] == '-') {
        ++i;
    }

    for (; isdigit(c = s[i]) && c != '\0'; ++i)
        ;

    if (c == '\0')
        return true;

    if (c != '.' && tolower(c) != 'e')
        return false;

    if (tolower(c) == 'e')
    {
        ++i;
        if ((c = s[i]) == '+' || c == '-')
            ++i;
        int pos = i;
        for (; isdigit(c = s[i]) && c != '\0'; ++i)
        ;
        if (c != '\0' || i == pos)
            return false;
        return true;
    }

    // c == '.'
    ++i;
    for (; isdigit(c = s[i]) && c != '\0'; ++i)
        ;
    if (c == '\0')
        return true;
    if (tolower(c) != 'e')
        return false;
    ++i;
    if ((c = s[i]) == '+' || c == '-')
        ++i;
    int pos = i;
    for (; isdigit(c = s[i]) && c != '\0'; ++i)
    ;
    if (c != '\0' || i == pos)
        return false;
    return true;
}

int getop(char s[]) {

    for (int i = 0; i < math_operations_len; ++i)
        if (strcmp(math_operations[i], s) == 0)
            return MATH_OP;

    for (int i = 0; i < math_functions_len; ++i)
        if (strcmp(math_functions[i], s) == 0)
            return MATH_FUN;

    for (int i = 0; i < stack_functions_len; ++i)
        if (strcmp(stack_operations[i], s) == 0)
            return STACK_OP;

    if (strlen(s) == 1 && isalpha(s[0]))
        return VAR;

    if (is_number(s))
        return NUMBER;

    return ERR;

    return 0;
}