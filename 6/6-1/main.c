// Упражнение 6.1. Haшa вepcия getword не обрабатывает должным образом знак подчеркивания, 
// строковые константы, комментарии и управляющие строки препроцессора. Напишите более 
// совершенный вариант программы.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key.h"

#define MAX_LEN 10

int getword(char *word, int lim);
int binsearch(char *word, key keytab[], int);
void print_tab(key[], int, char*);
int count_word(char *word, key tab[], int tab_size);

int main(int argc, char const *argv[])
{

    const char *allowed_symbols = "_-#0123456789";
    int NKEYS = sizeof(keytab) / sizeof(key);
    int PNKEYS = sizeof(pre_keytab) / sizeof(key);

    char prev_word[MAX_LEN], word[MAX_LEN];
    int pos;
    int inside_string = 0;
    int inside_comment = 0;

    getword(prev_word, MAX_LEN);

    count_word(prev_word, pre_keytab, PNKEYS);
    count_word(prev_word, keytab, NKEYS);

    while(getword(word, MAX_LEN) != EOF) {

        // printf("%s\n",word);
        count_word(word, pre_keytab, PNKEYS);
        count_word(word, keytab, NKEYS);

    }

    print_tab(keytab, NKEYS, "Keywords:");
    print_tab(pre_keytab, PNKEYS, "Preprocessor keywords:");

    return 0;
}


int count_word(char *word, key tab[], int tab_size) {
    int pos;
    if((pos = binsearch(word, tab, tab_size)) > -1)
        tab[pos].count += 1;        
}


void print_tab(key tab[], int len, char *word) {
    printf("\n%s\n", word);
    for (int i = 0; i < strlen(word); ++i)
        printf("-");
    printf("\n");

    for (int i = 0; i < len; ++i)
        if (tab[i].count > 0)
            printf("%-12s%3d\n", tab[i].word, tab[i].count);
}
