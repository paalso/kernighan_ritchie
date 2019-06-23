// Упражнение 5.6. Отберите подходящие программы из предыдущих глав и упражнений и перепишите их, 
// используя вместо индексирования указатели. Подойдут, в частности, программы getline (главы 1 и 4), 
// atoi, itoa и их варианты (главы 2, 3 и 4), reverse (глава 3), а также strindex и getop (глава 4).

#include <stdio.h>
#include <string.h>

#define MAXLINE 20

void reverse(char *);

// -------------------------------- Main --------------------------------
int main(void) {
    char s[MAXLINE];

    printf("Input a string:\n");
    scanf("%s", s);
    
    reverse(s);

    printf("%s", s);
}

// ---------------------------------------------------------
void reverse(char *s) {
    char tmp;
    char *endp = s + strlen(s) - 1;
    for (; s < endp; ++s, --endp)
        tmp = *s, *s = *endp, *endp = tmp;
}