#include <stdio.h>
#define MAXLINE 20

void strcpy(char *s, char *t) {
    while(*s++ = *t++)
        ;
}

// --- main -----------------------------------------
int main() {
    int total = 0;
    char from[MAXLINE], to[MAXLINE];

    printf("Input a string:\n");
    scanf("%s", from);
    printf("Copying...\n");
    strcpy(to, from);
    printf("New line:\n%s",to);

    return 0;
}

