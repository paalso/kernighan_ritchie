#include <stdio.h>
#include "sort_lines.h"

static int max_lines = 10;

int main(int argc, char const *argv[])
{
    char *lines[max_lines];
    int got_lines;

    if ((got_lines = readlines(lines, max_lines)) > 0) {
        quicksort(lines, 0, got_lines - 1);
        printf("Sorted:\n\n");
        writelines(lines, got_lines);
    } else {
        printf("Incorrect input!\n");
        return 1;
    }

    return 0;
}