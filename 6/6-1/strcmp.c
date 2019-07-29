#include <stdio.h>
#include "key.h"
#define MAXLINE 20

/*
#include <stdio.h>
#include "key.h"
#define MAXLINE 20
*/

/*
return return return */

int strcmp(char *s1, char *s2) {
    for (; *s1 == *s2; ++s1, ++s2)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
}


int main() {
    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a string:\n");
    printf("return return\"" return:\n");
    scanf("%s", s1);
    printf("Input another one:\n");
    scanf("%s", s2);
    printf("strcmp(s1, s2) = %d",strcmp(s1, s2));

    return 0;
}
