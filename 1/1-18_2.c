/* Упражнение 1.18. Напишите программу, которая будет в каждой вводимой строке
 заменять стоящие подряд символы пробелов и табуляций на один пробел и удалять пустые строки.
*/
// удаляет строки, т.е. содежащие в т.ч. один пробел (после обработки)

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 10000

// -------------------------------- Prototypes --------------------------------
int getLineRemovingBlanks(char[]);
bool stringConsistsSymbol(char[], char);

// -------------------------------- Main --------------------------------
int main(void)
{
    int len;
    char str[MAXLINE];

    while ((len = getLineRemovingBlanks(str)) > 0) {
        if (len > 2 || (len == 1 && !stringConsistsSymbol(str,' '))) {
            printf("%s",str);
        }
        
    }

    return 0;
}

// -------------------------------- Functions --------------------------------
int getLineRemovingBlanks(char s[]) {
    int c, i = 0;
    bool firstBlank = true;

    while((c = getchar()) != EOF) {

        if (c == ' ' || c == '\t') {
            if (firstBlank) {
                s[i++] = ' ';
                firstBlank = false;
            }
            continue;
        } else {
            s[i++] = c;
            if (c == '\n')
                break;
            firstBlank = true;
        }

    }
    s[i] = '\0';

    return i;
}

// ----------------------
bool stringConsistsSymbol(char s[], char symbol) {
    int c, i = 0;

    while((c = s[i++]) != '\0') {
        if (c == symbol) {
            return true;
        }
    }
    return false;
}