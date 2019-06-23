// Упражнение 5.5. Напишите варианты библиотечных функций strncpy, strncat и strncmp, 
// которые оперируют с первыми символами своих аргументов, число которых не превышает n. 
// Например, strncpy(t,s,n) копирует не более n символов t в s.

#include <stdio.h>
#define MAXLINE 20

void strncpy(char *t,char *s,int n) {
    int i = 0;
    while(*s++ = *t++) {
        ++i;
        if (i == n) {
            *s = '\0';
            return;
        }
    }
}

// --- main -----------------------------------------
int main() {
    int n;
    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a string:\n");
    scanf("%s", s1);
    
    printf("Input a number:\n");
    scanf("%d", &n);
    
    strncpy(s1, s2, n);

    printf("%s", s2);

    return 0;
}