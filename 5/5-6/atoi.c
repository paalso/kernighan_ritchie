// Упражнение 5.6. Отберите подходящие программы из предыдущих глав и упражнений и перепишите их, 
// используя вместо индексирования указатели. Подойдут, в частности, программы getline (главы 1 и 4), 
// atoi, itoa и их варианты (главы 2, 3 и 4), reverse (глава 3), а также strindex и getop (глава 4).

#include <stdio.h>
#include <ctype.h>

int atoi(char *);

// -------------------------------- Main --------------------------------
int main(void) {
    char str[20];
    scanf("%s", str);
    printf("Value:\n%d", atoi(str));
}

// ---------------------------------------------------------

int atoi(char *s) {
    char c;
    int value = 0;
    for (; isspace(*s); ++s)
        ;
    int sgn = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        ++s;
    for (; isdigit((c = *s)); ++s)
        value = 10 * value + (c - '0');

    return sgn * value;
}
4