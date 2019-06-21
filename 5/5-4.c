// Упражнение 5.4. Напишите функцию strend(s,t), которая выдает 1, если строка t расположена 
// в конце строки s, и нуль в противном случае.

#include <stdio.h>
#define MAXLINE 20

int strend(char *s, char *t) {
    while(*s)
        s++;

    char *tp = t;

    while(*tp)
        tp++;

    for (; *tp == *s; --s, --tp)
        if (*tp == *t)
            return 1;

    return 0;
}

// --- main -----------------------------------------
int main() {
    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a string:\n");
    scanf("%s", s1);
    
    printf("Input another one:\n");
    scanf("%s", s2);
    
    printf("%d", strend(s1, s2));

    return 0;
}