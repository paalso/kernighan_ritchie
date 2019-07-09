// Упражнение 1.20. Напишите программу detab, заменяющую символы табуляции 
// во вводимом тексте нужным числом пробелов (до следующего “стопа” табуляции). 
// Предполагается, что “стопы” табуляции расставлены на фиксированном расстоянии 
// друг от друга, скажем, через n позиций. Как лучше задавать n - в виде значения 
// переменной или в виде именованной константы?

#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 100
#define TAB_POS 8

// -------------------------------- Prototypes --------------------------------
int get_line(char[]);
void detab(const char[], char[]);

// -------------------------------- Main --------------------------------
int main(void) {
    char s[MAX_LEN], t[MAX_LEN];
    while(get_line(s) > 0) {
        detab(s,t);
        printf("%s\n",t);
    }
}


int get_line(char s[]) {
    int c, i = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

void detab(const char from[], char to[]) {
    int c;
    int j = 0;
    for (int i = 0; (c = from[i]) != '\0'; ++i)
        if (c == '\t')
            for (int k = 0, blanc_pos = TAB_POS - j % TAB_POS; k < blanc_pos; ++k)
                to[j++] = ' ';
        else
            to[j++] = c;
    to[j] = '\0';
}
