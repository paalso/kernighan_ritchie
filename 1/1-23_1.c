// Упражнение 1-23.
// Напишите программу удаления из C-программы всех комментариев. Не
// забывайте аккуратно обращаться с "закавыченными" строками и символьными
// константами. 

#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 10000

// -------------------------------- Prototypes --------------------------------
int get_line(char[]);

// -------------------------------- Main --------------------------------
int main(void) {
    char t[MAX_LEN];
    int len;
    int c, c_prev;
    int j = 0;
    int i = 0;
    int col = 0;
    bool inside_string = false;
    bool inside_comment = false;

    c = getchar();
    t[j++] = c;
    c_prev = c;

    while((c = getchar()) != EOF) {

        if (inside_comment)
        {
            if (c == '/' && c_prev == '*')
            {
                inside_comment = false;
            }
        } else 
        {
            if (c == '/' && c_prev == '/' && ! inside_string)
            {
                j -= 1;
                for (; c != '\n' && c != EOF; c = getchar())
                    ;
                inside_comment = false;
                if (col > 1)
                    t[j++] = '\n';
            }
            else if (((c == '*' && c_prev == '/')) && ! inside_string)
            {
                j -= 1;
                inside_comment = true;
            } else
            {
                if (c == '\"' && ! inside_string && ! inside_comment)
                    inside_string = true;
                else if (c == '\"' && inside_string && ! inside_comment)
                    inside_string = false;
                t[j++] = c;
            }
        }
        c_prev = c;
        if (c == '\n')
            col = 0;
        else
            col += 1;
    }
    t[j] = '\0';

    printf("%s\n",t);
}