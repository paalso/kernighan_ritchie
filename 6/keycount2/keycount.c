#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 15

typedef struct key {
    char *word;
    char count;
} key;

int getword(char *word, int lim);
key* binsearch(char *word, key *keytab, int);
void print_tab(key*, int, char*);

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
    int NKEYS = sizeof(keytab) / sizeof(key);

    char s[MAX_LEN];
    key *keyp;

    while(getword(s, MAX_LEN) != EOF)
        if((keyp = binsearch(s, keytab, NKEYS)))
            keyp -> count += 1;

    print_tab(keytab, NKEYS, "Keywords:");

    return 0;
}


key* binsearch(char *word, key *keytab, int tablen) {
    key *low = keytab;
    key *high = keytab + tablen - 1;
    key *mid;
    int cond;

    while(low <= high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid -> word)) == 0)
            return mid;
        else if (cond < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return NULL;
}


void print_tab(key *tab, int len, char *word) {
    printf("\n%s\n", word);
    for (int i = 0; i < strlen(word); ++i)
        printf("-");
    printf("\n");

    for (key *keyp = tab, *endp = keyp + len; keyp < endp; ++keyp)
        if (keyp -> count)
            printf("%-15s%3d\n", keyp -> word, keyp -> count);
}
