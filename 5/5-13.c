// Упражнение 5.13. Напишите программу tail, печатающую n последних введенных строк. 
// По умолчанию значение n равно 10, но при желании n можно задать с помощью аргумента. 
// Обращение вида tail -n печатает n последних строк. Программа должна вести себя осмысленно 
// при любых входных данных и любом значении n. Напишите программу так, чтобы наилучшим 
// образом использовать память; запоминание строк организуйте, как в программе сортировки, 
// описанной в параграфе 5.6, а не на основе двумерного массива с фиксированным размером строки.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

#define EXIT_ERR {fprintf(stderr, "Usage: tail -last_strings_to_print\n"); return 1;}
#define MIN(x,y) ((x) < (y) ? (x) : (y))

// -------------------------------- Prototypes --------------------------------
int get_line(char[], int);
int is_number(char[]);
void detab(int, int, const char[], char[]);
void writelines(char *lineptr[], int nlines);

// -------------------------------- Main --------------------------------
int main(int argc, char* argv[]) {
    char s[MAX_LEN];
    int tail = 10;      // по умолчанию

    if (argc > 2)
        EXIT_ERR
    else if (argc == 2) {
        if (argv[1][0] != '-' || ! is_number(argv[1] + 1))
            EXIT_ERR;
        tail = atoi(argv[1] + 1);
    } 

    char **lineptr = (char **) calloc(tail, sizeof(char*));

    int j = 0;      // прочитано строк
    int len = 0;

    while((len = get_line(s, MAX_LEN)) > 0) {
        char *p = (char *) calloc(len + 1, sizeof(char));
        strcpy(p, s);
        if (j < tail)
            lineptr[j] = p;
        else {
            for (int i = 0; i < tail - 1; ++i)
                lineptr[i] = lineptr[i + 1];
            lineptr[tail - 1] = p;  
        }
        j += 1;
    }
    writelines(lineptr, MIN(j, tail));

    for (int i = 0; i < MIN(j, tail); ++i)
        free(lineptr[i]);
    free(lineptr);

    return 0;
}


// --- get_line ---------------------------------------------------------
// get_line: читает строку в s, возвращает длину
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i] = '\0';
    return i;
}


// --- is_number ---------------------------------------------------------
int is_number(char s[]) {
    int i = 0;
    int digits = 0;
    int c;

    if ((c = s[i]) == '-' || c == '+' )
        ++i;
    if (s[i] == '\0')
        return 0; 

    for (; isdigit(c = s[i]) && c != '\0'; ++i)
        ;

    if (c == '\0')
        return 1;

    return 0;
}


// --- writelines ---------------------------------------------------------
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; ++i)
        printf("%s\n",lineptr[i]);
}