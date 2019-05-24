// Упражнение 1-23.
// Напишите программу удаления из C-программы всех комментариев. Не
// забывайте аккуратно обращаться с "закавыченными" строками и символьными
// константами. 


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN 300
#define N 10


// -------------------------------- Prototypes --------------------------------
int get_line(char[]);

// -------------------------------- Main --------------------------------
int main(void) {
    char s[MAX_LEN], t[MAX_LEN];
    int len;
    bool inside_string = false;
    bool inside_comment = false;

    while((len = get_line(s)) > 0) {
        remove_comments(s, t);
        printf("%s\n",t);
    }
}

// ----------------------------------------------------------------------
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

// ----------------------------------------------------------------------
int remove_comments(char s[], char t[]) {
    int j = 0;
    c_prev = getchar();
    while((c = getchar()) != '\0') {
        if (c == )
        {
            /* code */
        }
    }
}

