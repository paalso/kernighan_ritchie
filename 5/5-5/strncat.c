// Упражнение 5.5. Напишите варианты библиотечных функций strncpy, strncat и strncmp, 
// которые оперируют с первыми символами своих аргументов, число которых не превышает n. 

#include <stdio.h>
#define MAXLINE 20

// приписывает не более n символов t к s, завершая s символом '\0'
void strncat(char *t, char *s, int n) {
    int i = 0;
    while(*s)
        s++;

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

    printf("Input another one:\n");
    scanf("%s", s2);
    
    printf("Input a number:\n");
    scanf("%d", &n);
    
    strncat(s1, s2, n);

    printf("%s", s2);

    return 0;
}