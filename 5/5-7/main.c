// Упражнение 5.7. Напишите новую версию readlines, которая запоминала бы строки в массиве, 
// определенном в main, а не запрашивала память посредством программы alloc. 
// Насколько быстрее эта программа?

// Откровенно говоря, не до конца понял, что имеется в виду
// Сделал следующее
// readlines таки не запрашивает память, а запоминет строки в массиве строк char lines[][MAXLEN]
// при этом, т.к. в дальнейшем обрабатывать, в т.ч. сортировать удобнее массив ссылок на строки,
// то при запоминании строк еще и запоминются ссылки на них в отдельном массиве char *lineptr[]


#include <stdio.h>
#include "sort_lines.h"

static int max_lines = 10;

int main(int argc, char const *argv[])
{
    char *lineptr[max_lines];
    char lines[max_lines][MAXLEN];
    int got_lines;

    if ((got_lines = readlines(lines, lineptr, max_lines)) > 0) {
        quicksort(lineptr, 0, got_lines - 1);
        printf("Sorted:\n\n");
        writelines(lineptr, got_lines);
    } else {
        printf("Incorrect input!\n");
        return 1;
    }

    return 0;
}