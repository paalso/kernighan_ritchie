// Упражнение 5.6. Отберите подходящие программы из предыдущих глав и упражнений и перепишите их, 
// используя вместо индексирования указатели. Подойдут, в частности, программы getline (главы 1 и 4), 
// atoi, itoa и их варианты (главы 2, 3 и 4), reverse (глава 3), а также strindex и getop (глава 4).

#include <stdio.h>
#define MAXLINE 10


int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i] = '\0';
    return i;
}


// --- main -----------------------------------------
int main() {
    // char s1[MAXLINE], s2[MAXLINE];
    char s[MAXLINE];

    printf("Input a string:\n");
    get_line(s, MAXLINE);
    
    printf("%s", s);

    return 0;
}