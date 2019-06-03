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

    while(get_line(s, MAXLINE) > 0) {
        if (strindex(s, sample) >= 0) {
            total += 1;
            printf("%s\n",s);
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
int strindex(char s[], char sample[]) {
    for (int i = 0; s[i] != '\0'; ++i)
    {
        int k = 0;
        for (int j = i; s[j] != '\0' && s[j] == sample[k]; ++j, ++k)
            ;
        if (sample[k] == '\0' && k > 0)
            return i;
    }
    return -1;
}