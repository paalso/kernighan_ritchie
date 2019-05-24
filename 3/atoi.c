#include <stdio.h>
#include <ctype.h>

int atoi(char[]);

// -------------------------------- Main --------------------------------
int main(void) {
    char str[20];
    scanf("%s", str);
    printf("Value:\n%d", atoi(str));
}

// ---------------------------------------------------------

int atoi(char s[]) {
    int i;
    char c;
    int value = 0;
    for (i = 0; isspace(s[i]); ++i)
        ;
    int sgn = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        ++i;
    for (; isdigit((c = s[i])); ++i)
        value = 10 * value + (c - '0');

    return sgn * value;
}