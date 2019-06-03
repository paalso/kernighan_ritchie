// Упражнение 4-1.
// Составьте программу для функции rindex(s,t), которая возвращает позицию самого правого вхождения 
// t в s и -1, если s не содержит t.

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
/* find all lines matching a pattern */

int get_line(char[], int);
int rindex(char[], char[]);
int strlen(char[]);

// --- main -----------------------------------------
int main() {
    int total = 0;
    char s[MAXLINE], sample[MAXLINE] = "the";

    scanf("%s", s);
    printf("%d\n",rindex(s, sample));

    // while(get_line(s, MAXLINE) > 0) {
    //     if (rindex(s, sample) >= 0) {
    //         total += 1;
    //         printf("%s\n",s);
    //     }
    // }

    // printf("\nTotal mathing lines: %d\n",total);
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
int rindex(char s[], char sample[]) {
    for (int i = strlen(s) + 1 - strlen(sample); i >= 0; --i)
    {
        int k = 0;
        for (int j = i; s[j] != '\0' && s[j] == sample[k]; ++j, ++k)
            ;
        if (sample[k] == '\0' && k > 0)
            return i;
    }
    return -1;
}

// --------------------------------------------
int strlen(char s[]) {
    int i = 0;
    for (; s[i]; ++i)
        ;
    return i;
}