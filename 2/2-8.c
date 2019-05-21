// Упражнение 2.8. Напишите функцию rightrot (х, п), которая циклически
// сдвигает х вправо на п разрядов.


#include <stdio.h>
#include <stdbool.h>

unsigned int rightrot(unsigned int x, int n);

void print_bits(unsigned int);
void print_reversed_array(int*, int);


// -------------------------------- Main --------------------------------
int main(void) {
    unsigned int number, new_number;
    int shift;

    printf("Input an unsigned integer number:\n");
    scanf("%u", &number);
    printf("Positions to rotate to the right: ");
    scanf("%d", &shift);

    printf("\nTransformation...\n");
    new_number = rightrot(number, shift);
    printf("\nOriginal and result:\n");
    print_bits(number);
    print_bits(new_number);
    printf("%u\n", new_number);
} 

// ---------------------------------------------------------
unsigned int rightrot(unsigned int x, int shift) {
    return x >> shift | ((~(~0 << shift) & x) << (sizeof(unsigned int) * 8 - shift));
}

// ---------------------------------------------------------
void print_bits(unsigned int number) {
    int size = sizeof(unsigned int) * 8;
    // int *bit_array = (int*)malloc(size);
    int bit_array[size];
    for (int i = 0; i < size; ++i) {
        bit_array[i] = number & 1;
        number = number >> 1;
    }
    print_reversed_array(bit_array, size);
}

// ---------------------------------------------------------
void print_reversed_array(int *array, int len) {
    for (int i = len - 1; i >= 0; --i)
        printf("%d", *(array + i));
    printf("\n");
}