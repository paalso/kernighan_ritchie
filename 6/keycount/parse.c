#include <stdio.h>

#define MAX_LEN 10

int getword(char *word, int lim);

int main(int argc, char const *argv[])
{
    const char *allowed_symbols = "_-#0123456789";

    char s[MAX_LEN];
    int inside_string = 0;
    int inside_comment = 0;

    while(getword(s, MAX_LEN) > 0)

        printf("%s\n",s);

    return 0;
}