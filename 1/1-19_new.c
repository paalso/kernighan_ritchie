// Упражнение 1.19. Напишите функцию reverse(s), размещающую символы в строке s в обратном порядке. 
// Примените ее при написании программы, которая каждую вводимую строку располагает в обратном порядке.

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 10000

// -------------------------------- Prototypes --------------------------------
int get_line(char[]);
void reverse(char[]);

// -------------------------------- Main --------------------------------
int main(void)
{
    int len;
    char str[MAXLINE];

    while ((len = get_line(str)) > 0) {
        reverse(str);
        printf("%s\n", str);
        
    }

    return 0;
}

// -------------------------------- Functions --------------------------------
int get_line(char s[]) {
    int c, i = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

// ---------------------------
void reverse(char s[]) {
    int c;
    int len = 0;

    while((c = s[len++]) != '\0')
        ;
    len -= 1;

    for (int i = 0, mid = len / 2; i <= mid; ++i) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}