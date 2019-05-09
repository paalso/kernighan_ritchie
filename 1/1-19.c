// Упражнение 1.19. Напишите функцию reverse(s), размещающую символы в строке s в обратном порядке. 
// Примените ее при написании программы, которая каждую вводимую строку располагает в обратном порядке.

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 10000

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
int stringLength(const char[]);
void reverse(const char[], char[]);

// -------------------------------- Main --------------------------------
int main(void)
{
    int len;
    char strIn[MAXLINE], strOut[MAXLINE];

    while ((len = getLine(strIn)) > 0) {

        reverse(strIn,strOut);
        printf("%s\n", strOut);
        
    }

    return 0;
}

// -------------------------------- Functions --------------------------------
int getLine(char s[]) {
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
int stringLength(const char str[]) {
    int count = 0;
    while (str[count++] != '\0');
    return count - 1;
}

// ---------------------------
void reverse(const char sIn[], char sOut[]) {
    int c, len;

    len = stringLength(sIn);
    for (int i = 0; i < len; ++i) {
        sOut[i] = sIn[len - 1 - i];
    }

    sOut[len] = '\0';
}