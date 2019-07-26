#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

typedef struct key {
    char *word;
    char count;
} key;

int getword(char *word, int lim);
int binsearch(char *word, key keytab[], int);

key keytab[] = {
    "_Alignas", 0,
    "_Alignof", 0,
    "_Atomic", 0,
    "_Bool", 0,
    "_Complex", 0,
    "_Generic", 0,
    "_Imaginary", 0,
    "_Noreturn", 0,
    "_Static_assert", 0,
    "_Thread_local", 0,
    
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "inline", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "restrict", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};


int main(int argc, char const *argv[])
{
    const char *allowed_symbols = "_-#0123456789";
    int NKEYS = sizeof(keytab) / sizeof(key);

    char s[MAX_LEN];
    int pos;
    int inside_string = 0;
    int inside_comment = 0;

    while(getword(s, MAX_LEN) != EOF) {
        if((pos = binsearch(s, keytab, NKEYS)) > -1)
            keytab[pos].count += 1;
    }


    for (int i = 0; i < NKEYS; ++i)
        if (keytab[i].count > 0)
            printf("%-12s%3d\n", keytab[i].word, keytab[i].count);

    return 0;
}


int binsearch(char *word, key keytab[], int tablen) {
    int low = 0;
    int high = tablen - 1;
    int cond;

    while(low <= high) {
        int mid = (low + high) / 2;
        if ((cond = strcmp(word, keytab[mid].word)) == 0)
            return mid;
        else if (cond < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
