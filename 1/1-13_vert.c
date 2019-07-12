/* Упражнение 1.13. Напишите программу, печатающую гистограммы длин вводимых слов. 
Гистограмму легко рисовать горизонтальными полосами. Рисование вертикальными полосами 
- более трудная задача.
*/
#include <stdio.h>
#include <stdbool.h>

#define SYMBOL '#'
#define MAX_LENGTH 45
#define MAX_HISTO_ROW_LEN 22

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

    int max_index = 0;                      // соответствует наиболее часто встречающейся длине слова
    for (int i = 1; i <= upper_lim; ++i)             // будет соответствать ряду гистограммы
        if (word_length[i] > word_length[max_index]) // максимальной фиксированной длиной 
                max_index = i;                       // MAX_HISTO_ROW_LEN

    // масштаб пересчета в длину горизонтального ряда гистограммы
    float scale = (float) word_length[max_index] / MAX_HISTO_ROW_LEN;

    int hysto_lens[upper_lim];              // массив с длинами рядов гистограмм
    for (int i = 0; i <= upper_lim; ++i) 
        hysto_lens[i] = (int)(word_length[i] / scale);

    for (; hysto_lens[upper_lim] == 0; --upper_lim) // последний ряд с ненулевой длиной гистограммы
        ;

// вычисляем значение share и длину гистограммы в ряду "прочие"
    int sum_of_others = word_length[0];
    for (int i = upper_lim + 1; i < MAX_LENGTH; ++i)
        sum_of_others += word_length[i];

    hysto_lens[0] = (int)(sum_of_others / scale);

    printf("\n");
    for (int i = MAX_HISTO_ROW_LEN; i > 0; --i)
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
        printf(" %c", level <= array[i] ? SYMBOL : ' ');
    printf("  ");
    printf(" %c", level <= array[0] ? SYMBOL : ' ');
    putchar('\n');
}
