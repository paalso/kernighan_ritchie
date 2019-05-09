// Упражнение 1.14. Напишите программу, печатающую гистограммы частот встречаемости вводимых символов.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_HISTO_LEN 500

void printHorizontalHistogram(int);

int main(void)
{

    int c, histoLen, totalLetters = 0, totalWords = 0;
    int letters[26];
    bool isInWord = false;

    for (int i = 0; i < 26; ++i) {
        letters[i] = 0;
    }

    printf("\nInput a text:\n");

    while ((c = getchar()) != EOF) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            ++totalLetters;
            letters[c - 'a']++;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            isInWord = false;
        } else if (!isInWord) {
            isInWord = true;
            ++totalWords;
        }


    }

    for (int i = 0; i < 26; ++i) {
        printf("%c%10d%5.1f  ", 'a' + i, letters[i], 100.0 * letters[i] / totalLetters);

        histoLen = (int)(round((1.0 * letters[i] / totalLetters) * MAX_HISTO_LEN));
        // printf("%d\n", histoLen );
        printHorizontalHistogram(histoLen);

    }

    printf("\nTotal letters: %d\n", totalLetters);
    printf("Total words: %d\n", totalWords);
    printf("Average word's length: %.1f\n", (float)totalLetters / totalWords);

    return 0;
}

void printHorizontalHistogram(int count) {
    for (int i = 0; i < count; ++i) {
        putchar('*');
    }
    putchar('\n');
}