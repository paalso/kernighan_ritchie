#include <stdio.h>
#include <ctype.h>
#include <string.h>
// #include "calc.h"

#define NUMBER 0
#define MATH_OP 1
#define MATH_FUN 2
#define STACK_OP 3
#define VAR 4

char math_operations[] = {"+", "-", "*", "/", "%"};
char math_functions[] = {"sin", "exp", "pow"};
char stack_operations[] = {"top", "double", "inverse"};

int getop(char s[]) {
    if (strlen(s) == 1 && isalpha(s[0]))
        return VAR;
    return 0;
}