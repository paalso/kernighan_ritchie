// Упражнение 2.9. Применительно к числам, в представлении которых
// использован дополнительный код, выражение х &= (х-1) уничтожает
// самую правую 1 в х. Объясните, почему. Используйте это наблюдение при
// написании более быстрого варианта функции bitcount.


#include <stdio.h>
#include <stdbool.h>

unsigned int bitcount(unsigned int x);

void print_bits(unsigned int);
void print_reversed_array(int*, int);


// -------------------------------- Main --------------------------------
int main(void) {
    unsigned int number, new_number;
    int shift;

    printf("Input an unsigned integer number:\n");
    scanf("%u", &number);
    print_bits(number);

    printf("Sum of bits: %d\n", bitcount(number));
} 

// ---------------------------------------------------------
unsigned int bitcount(unsigned int x) {
    int b = 0;

    for (; x > 0; x &= x - 1)
        b += 1;

    return b;
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
gt
// ---------------------------------------------------------
void print_reversed_array(int *array, int len) {
    for (int i = len - 1; i >= 0; --i)
        printf("%d", *(array + i));
    printf("\n");
}