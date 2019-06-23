// Упражнение 5.6. Отберите подходящие программы из предыдущих глав и упражнений и перепишите их, 
// используя вместо индексирования указатели. Подойдут, в частности, программы getline (главы 1 и 4), 
// atoi, itoa и их варианты (главы 2, 3 и 4), reverse (глава 3), а также strindex и getop (глава 4).

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
/* find all lines matching a pattern */

int get_line(char[], int);
int strindex(char[], char[]);

// --- main -----------------------------------------
int main() {
    int total = 0;
    char s[MAXLINE], sample[MAXLINE] = "the";

    // printf("Sample:\n");
    // scanf("%s", s);

    printf("Input a text:\n");

    while(get_line(s, MAXLINE) > 0) {
        if (strindex(s, sample) >= 0) {
            total += 1;
            // printf("%s\n",s);
        }
    }

    printf("\nTotal mathing lines: %d\n",total);
    return 0;
}

// --------------------------------------------
int get_line(char s[], int lim) {
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n' && --lim > 0) {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// --------------------------------------------
int strindex(char *s, char *sample) {

    for (char *sp = s; *sp; ++sp)
    {
        char *samplep = sample;
        for (char *p = sp; *p && *p == *samplep; ++p, ++samplep)
            ;
        if (! *samplep && samplep - sample)
            return sp - s;
    }
    return -1;
}