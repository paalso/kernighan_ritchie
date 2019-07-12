/* Упражнение 1.13. Напишите программу, печатающую гистограммы длин вводимых слов. 
Гистограмму легко рисовать горизонтальными полосами. Рисование вертикальными полосами 
- более трудная задача.
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 45
#define HISTO_LEN_PER_ITEM 10

void print_line(int[], int, int);

int main(void)
{
    int array[] = {1, 0, 2, 6, 2};
    const int width = 5;

    for (int i = 6; i > 0; --i)
    {
        print_line(array, width, i);
    }
    

}

void print_line(int array[], int width, int level) {
    for (int i = 0; i < width; ++i)
        printf(" %c", level <= array[i] ? '*' : ' ');
    putchar('\n');
}
