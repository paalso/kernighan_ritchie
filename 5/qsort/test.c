#include <stdio.h>
#include "qsort.h"

#define MAX_LEN 10

static int max_lines = 10;

int main(int argc, char const *argv[])
{

    char s[max_lines];
    while(get_line(s, MAX_LEN) > 0)
        printf("%s\n",s);

    return 0;
}