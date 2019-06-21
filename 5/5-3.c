// Упражнение 5-3.

#include <stdio.h>
#define MAXLINE 20

void strcat(char *s, char *t) {
    for (; *s; ++s)
        ;

    for (; *t; ++s, ++t)
        *s = *t;

    *s = '\0';
}

// --- main -----------------------------------------
int main() {
    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a string:\n");
    scanf("%s", s1);
    
    printf("Input another one:\n");
    scanf("%s", s2);
    strcat(s1, s2);
    
    printf("%s", s1);

    return 0;
}