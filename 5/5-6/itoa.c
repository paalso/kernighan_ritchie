// Упражнение 5.6. Отберите подходящие программы из предыдущих глав и упражнений и перепишите их, 
// используя вместо индексирования указатели. Подойдут, в частности, программы getline (главы 1 и 4), 
// atoi, itoa и их варианты (главы 2, 3 и 4), reverse (глава 3), а также strindex и getop (глава 4).

#include <stdio.h>
#include <string.h>

void itoa(int, char *);
void reverse(char *);

// -------------------------------- Main --------------------------------
int main(void) {
    int n;
    char str[20];
    printf("Number: ");
    scanf("%d", &n);
    itoa(n, str);

    printf("String:\n%s", str);
}

// ---------------------------------------------------------

void itoa(int n, char *s) {
    char *sp = s;
    int sgn;
    if ((sgn = n) < 0)
        n = - n;

    do {
        *sp++ = (n % 10) + '0';
    } while((n /= 10) > 0);
    if (sgn < 0)
        *sp++ = '-'; 
    *sp = '\0';
    reverse(s);
}

// ---------------------------------------------------------
void reverse(char *s) {
    char tmp;
    char *endp = s + strlen(s) - 1;
    for (; s < endp; ++s, --endp)
        tmp = *s, *s = *endp, *endp = tmp;
}