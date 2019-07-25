#include <stdio.h>

#define MAX_LEN 10

int getword(char *word, int lim);

int main(int argc, char const *argv[])
{
    char s[MAX_LEN];
    while(getword(s, MAX_LEN) > 0)
        printf("%s ",s);

    return 0;
}