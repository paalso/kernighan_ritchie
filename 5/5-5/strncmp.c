// Упражнение 5.5. Напишите варианты библиотечных функций strncpy, strncat и strncmp, 
// которые оперируют с первыми символами своих аргументов, число которых не превышает n. 

#include <stdio.h>
#define MAXLINE 20

#undef strncmp  // ?

// сравнивает не более n символов s и t; 
// возвращает < 0, если s < t, 0, если s == t, и > 0, если s > t
int strncmp(char *s, char *t, int n) {
    int i = 0;
    for (; *s == *t; ++s, ++t) {
        ++i;
        if (i == n)
            return *s - *t;        
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

// --- main -----------------------------------------
int main() {
    int n;
    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a string:\n");
    scanf("%s", s1);

    printf("Input another one:\n");
    scanf("%s", s2);
    
    printf("Input a number:\n");
    scanf("%d", &n);
    
    strncat(s1, s2, n);

    printf("%d", strncmp(s1, s2, n));

    return 0;
}