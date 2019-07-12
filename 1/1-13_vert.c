/* Упражнение 1.13. Напишите программу, печатающую гистограммы длин вводимых слов. 
Гистограмму легко рисовать горизонтальными полосами. Рисование вертикальными полосами 
- более трудная задача.
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 45
#define HISTO_LEN_PER_ITEM 7

void print_line(int[], int, int);

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

    // расчет данных для вывода
    int hysto_lens[upper_lim];
    int max_height = 0;
    for (int i = 0; i <= upper_lim; ++i) {
        share = (float) word_length[i] / total_words;
        int current = hysto_lens[i] = (int)(share * HISTO_LEN_PER_ITEM * non_zero);
        if (current > max_height)
            max_height = current;
    }

    for (; hysto_lens[upper_lim] == 0; --upper_lim)
        ;

    printf("\n");
    for (int i = max_height; i > 0; --i)
        print_line(hysto_lens, upper_lim, i);

    // печать подписей: 1, 2, ....
    for (int i = 1; i <= upper_lim; ++i)
        if (i % 2 == 1)
            printf("%2d",i);
        else
            printf("  ");
    printf("   >\n\n", hysto_lens[0]);
    printf("  Words length distribution\n");
    return 0;
}

void print_line(int array[], int width, int level) {
    for (int i = 1; i <= width; ++i)
        printf(" %c", level <= array[i] ? '*' : ' ');
    printf("  ");
    printf(" %c", level <= array[0] ? '*' : ' ');
    putchar('\n');
}
