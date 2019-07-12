/* Упражнение 1.13. Напишите программу, печатающую гистограммы длин вводимых слов. 
Гистограмму легко рисовать горизонтальными полосами. Рисование вертикальными полосами 
- более трудная задача.
*/
#include <stdio.h>
#include <stdbool.h>

void printHorizontalHistogram(int);

int main(void)
{

    int c;
    int lettersInAWord = 0;
    bool isInWord = false;

    printf("\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' ||  c == '\t' || c == '\n') {
            if (isInWord) {
                printHorizontalHistogram(lettersInAWord);
                lettersInAWord = 0;
                isInWord = false;
            }
        } else {
            lettersInAWord++;
            isInWord = true;
        }
    }

    return 0;
}

void printHorizontalHistogram(int count) {
    for (int i = 0; i < count; ++i) {
        putchar('*');
    }
    putchar('\n');
}
