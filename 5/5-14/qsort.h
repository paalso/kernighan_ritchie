#define MAXLEN 100

int get_line(char s[], int lim);

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void quicksort(void *lineptr[], int left, int right,
    int (*comp)(void *, void *), int range);

int numcmp(char *, char *);
