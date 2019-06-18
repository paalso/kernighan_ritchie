#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "calc.h"

/*
#define NUMBER 0
#define MATH_OP 1
#define MATH_FUN 2
#define STACK_OP 3
#define VAR 4
#define ERR 5

char *math_operations[] = {"+", "-", "*", "/", "%"};
int math_operations_len = 5;

char *math_functions[] = {"sin", "exp", "pow"};
int math_functions_len = 3;

char *stack_operations[] = {"top", "double", "inv", "prnlst"};
int stack_functions_len = 4;

_Bool is_number(char s[]) {
    int i = 0;
    int digits = 0;
    int c;

    if (s[0] == '-')
        ++i;
    if (s[i] == '\0')
        return false;    

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
*/


int main() {

    char s[20];

    printf("Input a string:\n");
    scanf("%s", s);
    printf("Operation = %d\n",getop(s));
    printf("Is number = %d\n",is_number(s));
    if (is_number(s))
        printf("Number = %g\n",atof(s));
    // for (int i = 0; i < 5; ++i)
    //     printf("%d\n",strcmp (ops[i], s));


 return 0;
}