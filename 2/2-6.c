// Упражнение  2.З.  Напишите функцию setbits(x, p, n, y), возвращающую значение x, 
// в котором n битов, начиная с p-й позиции, заменены на n правых разрядов из y 
// (остальные биты не изменяются).


#include <stdio.h>
#include <stdbool.h>

unsigned int getbits(unsigned int x,int p,int n);
unsigned int setbits(unsigned int x,int p,int n, unsigned int y);

void print_bits(unsigned int);
void print_reversed_array(int*, int);


// -------------------------------- Main --------------------------------
int main(void) {
    unsigned int number, new_number;
    unsigned int y = 253016411;
    int pos, len;

    printf("Input an unsigned integer number:\n");
    scanf("%u", &number);
    printf("Position in the number: ");
    scanf("%d", &pos);
    printf("Length of the segment: ");
    scanf("%d", &len);

    printf("Mask number = %u :\n", y);
    print_bits(y);

    printf("\nTransformation...\n");
    new_number = setbits(number, pos, len, y);
    printf("\nOriginal and result:\n");
    print_bits(number);
    print_bits(new_number);,ь
    printf("%u\n", new_number);
}ь 

// ---------------------------------------------------------
unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
    int shift = p - n + 1;
    unsigned int mask = y & ~(~0 << n);
    return ((((x >> shift) & (~0 << n)) | mask) << shift) | x & ~(~0 << shift);
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
