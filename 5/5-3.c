// Упражнение 5.3. Используя указатели, напишите функцию strcat, которую мы рассматривали 
// в главе 2 (функция strcat(s,t) копирует строку t в конец строки s).

#include <stdio.h>
#define MAXLINE 20

void strcat(char *s, char *t) {
    while(*s)
        s++;

    while(*s++ = *t++)
        ;
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