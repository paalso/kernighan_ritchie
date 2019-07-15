// Упражнение 5.12. Расширьте возможности entab и detab таким образом, чтобы при обращении вида
// entab -m +n
// "стопы" табуляции начинались с m-й позиции и выполнялись через каждые n позиций. 
// Разработайте удобный для пользователя вариант поведения программы по умолчанию 
// (когда нет никаких аргументов).

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 100

#define EXIT_ERR {fprintf(stderr, "Usage: detab -starting_column +tab_size\n"); return 1;}

// -------------------------------- Prototypes --------------------------------
int get_line(char[], int);
int is_number(char[]);
void detab(int, int, const char[], char[]);

// -------------------------------- Main --------------------------------
int main(int argc, char* argv[]) {
    char s[MAX_LEN], t[MAX_LEN];

    // по умолчанию
    int start_tab = 0;
    int tab = 4;

    // Длинная проверка из-за того, что признаки параметров - разные (+ и -)
    // По-хорошему, ее нужно было бы усовершенствовать - добавить проверку того,
    // что после +/- введены числа

    if (argc > 3 )
        EXIT_ERR
    else if ((argc == 3) && 
        ! ((argv[1][0] == '+' && argv[2][0] == '-') ||
            (argv[1][0] == '-' && argv[2][0] == '+'))) {
        EXIT_ERR
    }
    else if (argc == 3) {
        if(! is_number(argv[1] + 1) || ! is_number(argv[2] + 1))
            EXIT_ERR;

        if (argv[1][0] == '-') {
            start_tab = atoi(++argv[1]);
            tab = atoi(++argv[2]);
        } else {
            start_tab = atoi(++argv[2]);
            tab = atoi(++argv[1]);
        }
    } else if (argc == 2) {

        if(! is_number(argv[1] + 1))
            EXIT_ERR;

        if (argv[1][0] == '-')
            start_tab = atoi(++argv[1]);
        else if (argv[1][0] == '+')
            tab = atoi(++argv[1]);
        else
            EXIT_ERR
    }


    // printf("start col = %d\n", start_col);
    // printf("tab = %d\n", tab);


    while(get_line(s, MAX_LEN) > 0) {
        detab(start_tab, tab, s,t);
        printf("%s\n",t);
    }
    return 0;
}


// --- get_line ---------------------------------------------------------
#include <stdio.h>

int get_line(char s[], int lim) {
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n' && --lim > 0) {
        s[i++] = c;
    }
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


// --- detab ---------------------------------------------------------
void detab(int start, int tab, const char from[], char to[]) {
    int c;
    int i = 0;
    int j = 0;
    for (; i < start * tab && (c = from[i]) != '\0'; ++i)
        to[j++] = c;

    // int tab_counter = 0;
    // while(c != '\0' && tab_counter < start) {
    //     c = from[i++];
    //     to[j++] = c;
    //     if (c == '\t' || i % tab == 0)
    //         tab_counter += 1;
    // }


    if (!c) {
        to[j] = '\0';
        return;
    }

    for (; (c = from[i]) != '\0'; ++i) {
        if (c == '\t') {
            for (int k = 0, blanc_pos = tab - j % tab; k < blanc_pos; ++k)
                to[j++] = ' ';
        }
        else {
            to[j++] = c;
        }
    }
    to[j] = '\0';
}
