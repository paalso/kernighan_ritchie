// Упражнение 1.9. Напишите программу, копирующую символы ввода в выходной поток 
// и заменяющую стоящие подряд пробелы на один пробел.

#include <stdio.h>
#include <stdbool.h>

#define IN true
#define OUT false

int main(void)
{

    int c;
    bool nextBlanc = false;

    printf("\nInput a text\n");

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            if (nextBlanc)
                continue;
            else {
                putchar(c);
                nextBlanc = true;
            }
        } else {
            putchar(c);
            nextBlanc = false;
        }
    }
    return 0;
}