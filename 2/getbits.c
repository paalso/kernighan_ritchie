
#include <stdio.h>
#include <stdbool.h>

unsigned int getbits(unsigned int x,int p,int n);

void print_bits(unsigned int);
void print_reversed_array(int*, int);


// -------------------------------- Main --------------------------------
int main(void) {
    unsigned int number, new_number;
    int pos, len;

    printf("Input an unsigned integer number:\n");
    scanf("%u", &number);
    printf("Position in the number:\n");
    scanf("%d", &pos);
    printf("Length of the segment:\n");
    scanf("%d", &len);
    // printf("It's binary representation: ");
    print_bits(number);

    new_number = getbits(number, pos, len);
    printf("\nTransformation...\n");
    // printf("It's binary representation: ");
    print_bits(new_number);
    printf("%u\n", new_number);
}

// Возвращает (сдвинутыми к правому краю) начинающиеся с позиции р поле переменной х длиной n битов. 
// Мы предполагаем , что крайний правый бит имеет номер 0, и что n и р - 
// разумно заданные положительные числа. Например, getbits(х,4,3) возвращает 
// сдвинутыми к правому краю биты, занимающие позиции 4,3 и 2.
unsigned int getbits(unsigned int x,int p,int n) {
    return (x >> (p - n + 1)) & ~(~0 << n);
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
