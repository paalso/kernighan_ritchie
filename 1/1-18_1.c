/* Упражнение 1.18. Напишите программу, которая будет в каждой вводимой строке
 заменять стоящие подряд символы пробелов и табуляций на один пробел и удалять пустые строки.
*/
// удаляет только абсолютно пустые строки, т.е. содежащие только '\n'


#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 10000

// -------------------------------- Prototypes --------------------------------
int getLineRemovingBlanks(char[]);

// -------------------------------- Main --------------------------------
int main(void)
{
    int len;
    char str[MAXLINE];

    while ((len = getLineRemovingBlanks(str)) > 0) {
        if (len > 1) {
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