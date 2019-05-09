// Упражнение 1.12. Напишите программу, которая печатает содержимое своего ввода, 
// помещая по одному слову на каждой строке.

#include <stdio.h>
#include <stdbool.h>

int main(void)
{

    int c;
    bool nextBlanc = false;

    printf("\nInput a text\n");

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (nextBlanc) {
                continue;
            } else {
                putchar('\n');
                nextBlanc = true;
            }
        } else {
            putchar(c);
            nextBlanc = false;
        }
    }

    return 0;
}