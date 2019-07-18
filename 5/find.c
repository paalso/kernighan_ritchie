#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char *line, int max);
/* find: печать строк с образцом, заданным 1-м аргументом */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: find pattern\n"); 
        return 1;
    }
    char *needle = argv[1];

    int len, counter = 0;
    char s[MAXLINE];

    while((len = get_line(s, MAXLINE)) > 0) {
        if (strstr(s, needle)) {
            printf("%s\n", s);
            counter += 1;
        }
    }
    printf("\nFound: %d strings\n",counter);

    return 0;
}


// --- get_line ---------------------------------------------------------
// get_line: читает строку в s, возвращает длину
int get_line(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i] = '\0';
    return i;
}