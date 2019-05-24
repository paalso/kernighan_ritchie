// Упражнение 3.1. В нашей программе бинарного поиска внутри цикла осуществляются две проверки, 
// хотя могла быть только одна (при увеличении числа проверок вне цикла). Напишите программу, 
// предусмотрев в ней одну проверку внутри цикла. Оцените разницу во времени выполнения.

#include <stdio.h>

int binsearch(int value, int array[], int len);

// -------------------------------- Main --------------------------------
int main(void) {
    int array[] = {0, 1, 1, 4, 5, 6, 9, 12, 12, 15};
    int len = 10;
    int value, key;

    printf("Value to find: ");
    scanf("%d", &value);
    key = binsearch(value, array, len);
    printf("%d\n", key);
}

// ---------------------------------------------------------
int binsearch(int value, int array[], int len) {
    int low = 0;
    int high = len - 1;
    int mid;

    while(low < high) {
        mid = (high + low) / 2;
        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    if (array[high] == value)
        return high;
    return -1;
}