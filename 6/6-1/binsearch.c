#include <string.h>
// #include "key.h"

typedef struct key {
    char *word;
    char count;
} key;

int binsearch(char *word, key keytable[], int tablen) {
    int low = 0;
    int high = tablen - 1;
    int cond;

    while(low <= high) {
        int mid = (low + high) / 2;
        if ((cond = strcmp(word, keytable[mid].word)) == 0)
            return mid;
        else if (cond < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
