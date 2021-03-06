// Упражнение 1.16. Перепишите main предыдущей программы так, 
// чтобы она могла печатать самую длинную строку без каких-либо ограничений на ее размер.

#include <stdio.h>

#define MAXLINE 10000

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
void copyLine(char[], char[]);

// -------------------------------- Main --------------------------------
int main(void)
{
    int len, maxLen = 0;
    char str[MAXLINE], maxStr[MAXLINE];

    while ((len = getLine(str)) > 0) {
        // printf("%s",str);
        if (len > maxLen) {
            copyLine(str, maxStr);
            // printf("%s",maxStr);
            maxLen = len;
        }
    }

    if (maxLen > 0) {
        printf("\nLongest line:\n");
        printf("%s", maxStr);
        printf("It's length: %d", maxLen);
    } else {
        printf("Alas, empty file\n");
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