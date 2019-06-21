#include <stdio.h>
#define MAXLINE 20

int strcmp(char *s1, char *s2) {
    for (; *s1 == *s2; ++s1, ++s2)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
}

// --- main -----------------------------------------
int main() {
    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a string:\n");
    scanf("%s", s1);
    printf("Input another one:\n");
    scanf("%s", s2);
    printf("strcmp(s1, s2) = %d",strcmp(s1, s2));

    return 0;
}

