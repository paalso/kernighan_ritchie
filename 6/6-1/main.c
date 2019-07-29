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

    int NKEYS = sizeof(keytab) / sizeof(key);
    int PNKEYS = sizeof(pre_keytab) / sizeof(key);

    char prev_word[MAX_LEN], word[MAX_LEN];
    int pos;
    int in_string = 0;
    int in_comment = 0;    // комментарий типа /*
    // int in_comment2 = 0;    // комментарий типа //

    while(getword(word, MAX_LEN) != EOF) {
        if (!strcmp(word, "/*") && !in_string && !in_comment) 
            in_comment = 1;
        else if (!strcmp(word, "\"") && !in_string && !in_comment)
            in_string = 1;
        else if (!strcmp(word, "\"") && in_string && !in_comment)
            in_string = 0;
        else if (!strcmp(word, "*/") && !in_string && in_comment)
            in_comment = 0;
        else if (!in_string && !in_comment) {
            count_word(word, pre_keytab, PNKEYS);
            count_word(word, keytab, NKEYS);            
        }
    }

    print_tab(keytab, NKEYS, "Keywords:");
    print_tab(pre_keytab, PNKEYS, "Preprocessor keywords:");

    return 0;
}

// ищет прочитанное слово в таблице, при нахождении учитывает это в таблице
int count_word(char *word, key tab[], int tab_size) {
    int pos;
    if((pos = binsearch(word, tab, tab_size)) > -1)
        tab[pos].count += 1;        
}

// печатает (заполненную) таблицу
void print_tab(key tab[], int len, char *word) {
    printf("\n%s\n", word);
    for (int i = 0; i < strlen(word); ++i)
        printf("-");
    printf("\n");

    for (int i = 0; i < len; ++i)
        if (tab[i].count > 0)
            printf("%-12s%3d\n", tab[i].word, tab[i].count);
}
