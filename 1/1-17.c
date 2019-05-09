// Упражнение 1.17. Напишите программу печати всех вводимых строк, содержащих более 80 символов.

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 10000
#define LIMIT 5	// 80

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
void copyLine(char[], char[]);

// -------------------------------- Main --------------------------------
int main(void)
{
    int len, maxLen = 0;
    char str[MAXLINE], maxStr[MAXLINE];

    while ((len = getLine(str)) > 0) {
        // printf("%s   %d\n",str,len);
        if (len > LIMIT) {
            printf("%s",str);
        }
    }

    return 0;
}

// -------------------------------- Functions --------------------------------
int getLine(char s[]) {
    int c, i = 0;

    while((c = getchar()) != EOF) {
        s[i++] = c;
        if (c == '\n')
            break;
    }
    s[i] = '\0';

    return i;
}

// -------------------
void copyLine(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i++]) != '\0');
}