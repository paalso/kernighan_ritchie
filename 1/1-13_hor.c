/* Упражнение 1.13. Напишите программу, печатающую гистограммы длин вводимых слов. 
Гистограмму легко рисовать горизонтальными полосами. Рисование вертикальными полосами 
- более трудная задача.
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 45
#define HISTO_LEN_PER_ITEM 10

void printHorizontalHistogram(int);

int main(void)
{
    // const char punctuation[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    int c;
    int lettersInAWord = 0;
    bool isInWord = false;

    int total_words = 0;
    int word_length[MAX_LENGTH + 1];
    float share;

    for (int i = 0; i <= MAX_LENGTH; ++i)
        word_length[i] = 0;

    printf("\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' ||  c == '\t' || c == '\n') {
            if (isInWord) {
                ++total_words;
                if (lettersInAWord > MAX_LENGTH)
                    ++word_length[0];
                else 
                    ++word_length[lettersInAWord];
                // printHorizontalHistogram(lettersInAWord);
                lettersInAWord = 0;
                isInWord = false;
            }
        } else {
            lettersInAWord++;
            isInWord = true;
        }
    }

    // To find the longest word info in array 'word_length'
    int upper_lim = MAX_LENGTH;
    while (word_length[upper_lim] == 0)
        upper_lim -= 1;

    // Find non-zero elements number
    int non_zero = 0;
    for (int i = 0; i <= upper_lim; ++i)
        if (word_length[i])
            non_zero += 1;

    // Version 1
    // Способ печати диаграм не вполне удовлетворителен: в нек-х случаях самый длинный столбец
    // может выходить за пределы экрана

    printf("Words length distribution info\n");
    printf("===============================\n\n");
    for (int i = 1; i <= upper_lim; ++i) {
        share = (float) word_length[i] / total_words;
        printf("%2d : %5.1f%%   ", i, share * 100);
        printHorizontalHistogram((int)(share * HISTO_LEN_PER_ITEM * non_zero));
    }
    share = (float) word_length[0] / total_words;
    printf(">  : %5.1f%%   ", share * 100);
    printHorizontalHistogram((int)(share * HISTO_LEN_PER_ITEM * non_zero));

    return 0;
}

void printHorizontalHistogram(int count) {
    for (int i = 0; i < count; ++i) {
        putchar('*');
    }
    putchar('\n');
}
