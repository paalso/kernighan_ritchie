// Упражнение 4-2.
// Расширьте atof таким образом, чтобы она могла работать с числами вида
//      123.45е-6
// где за числом с плавающей точкой может следовать 'E' и показатель экспоненты, возможно со знаком.


#include <stdio.h>
#include <ctype.h>

double atof(char[]); /* convert string s to double */
double power(double, int); 

// -------------------------------- Main --------------------------------
int main(void) {
    char str[20];
    scanf("%s", str);
    printf("Value:\n%lf", atof(str));
}

// ---------------------------------------------------------



double atof(char s[]) {
/* convert string s to double */
    char c;
    double f = 0.0;
    int i = 0;
    int sgn = 1;
    double pow = 1;
    int exp_sgn = 1;
    int exp = 0;

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

    if (tolower(s[i]) == 'e')
        ++i;
    if ((c = s[i]) == '-')
        exp_sgn = -1;
    if (c == '-' || c == '+')
        ++i;

    for (; isdigit((c = s[i])); ++i)
        exp = 10 * exp + (c - '0');

    f = sgn * f / pow;

    return exp_sgn < 0 ? f / power(10.0, exp) : f * power(10.0, exp);
}


double power(double f, int exp) {
    double p = 1.0;
    for (; exp > 0; --exp)
        p *= f;
    return p;
}