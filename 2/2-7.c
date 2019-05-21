// Упражнение 2.7. Напишите функцию invert (х, р, п), возвращающую
// значение х с инвертированными п битами, начиная с позиции р (остальные
// биты не изменяются).


#include <stdio.h>
#include <stdbool.h>

unsigned int invert(unsigned int x, int p, int n);

void print_bits(unsigned int);
void print_reversed_array(int*, int);


// -------------------------------- Main --------------------------------
int main(void) {
    unsigned int number, new_number;
    int pos, len;

    printf("Input an unsigned integer number:\n");
    scanf("%u", &number);
    printf("Position in the number: ");
    scanf("%d", &pos);
    printf("Length of the segment: ");
    scanf("%d", &len);

    printf("\nTransformation...\n");
    new_number = invert(number, pos, len);
    printf("\nOriginal and result:\n");
    print_bits(number);
    print_bits(new_number);
    printf("%u\n", new_number);
} 

// ---------------------------------------------------------
unsigned int invert(unsigned int x, int p, int n) {
    int shift = p - n + 1;
    unsigned int mask = ~(~0 << n);
    return (((x >> shift) ^ mask) << shift) | x & ~(~0 << shift);
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
