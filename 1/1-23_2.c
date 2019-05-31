// Упражнение 1-23.
// Напишите программу удаления из C-программы всех комментариев. Не
// забывайте аккуратно обращаться с "закавыченными" строками и символьными
// константами. 


#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 300
#define N 10


// -------------------------------- Prototypes --------------------------------
int get_line(char[]);
void remove_comments(char s[], char t[], bool*, bool*);

// -------------------------------- Main --------------------------------
int main(void) {
    char s[MAX_LEN], t[MAX_LEN];
    int len;
    bool inside_string = false;
    bool inside_comment = false;

    while((len = get_line(s)) > 0) {
        remove_comments(s, t, &inside_string, &inside_comment);
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
void remove_comments(char s[], char t[], bool *inside_string, bool *inside_comment) {

    char c;
    int j = 0;
    int i = 0;

    c = s[i++];
    if (c == '\0')
        return;
    if (! *inside_comment)
        t[j++] = c;

    while((c = s[i]) != '\0') {

        if (*inside_comment)
        {
            if (c == '/' && s[i - 1] == '*')
            {
                *inside_comment = false;
            }
        } else 
        {
            if (c == '/' && s[i - 1] == '/' && ! *inside_string)
            {
                for (; c != '\0'; ++i)
                {
                    c = s[i];
                }
                t[j - 1] = '\0';
                *inside_comment = false;
                return;
            }
            else if (((c == '*' && s[i - 1] == '/')) && ! *inside_string)
            {
                j -= 1;
                *inside_comment = true;
            } else
            {
                if (c == '\"' && ! *inside_string && ! *inside_comment)
                    *inside_string = true;
                else if (c == '\"' && *inside_string && ! *inside_comment)
                    *inside_string = false;
                t[j++] = c;
            }
        }
        i++;
    }

    t[j] = '\0';

}

