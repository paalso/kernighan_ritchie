#include <stdio.h>
#include <ctype.h>

double atof(char[]); /* convert string s to double */

// -------------------------------- Main --------------------------------
int main(void) {
    char str[20];
    scanf("%s", str);
    printf("Value:\n%f", atof(str));
}

// ---------------------------------------------------------



double atof(char s[]) {
/* convert string s to double */
    char c;
    double f = 0.0;
    int i = 0;
    int sgn = 1;
    double pow = 1;

    for (; isspace(s[i]); ++i)
        ;
    if ((c = s[i]) == '-')
        sgn = -1;
    if (c == '-' || c == '+')
        ++i;
    for (; isdigit((c = s[i])); ++i)
        f = 10.0 * f + (c - '0');
    if (s[i] == '.')
        ++i;
    for (; isdigit((c = s[i])); ++i) {
        f = 10.0 * f + (c - '0');
        pow *= 10;
    }
    return sgn * f / pow;
}
