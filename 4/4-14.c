// Упражнение 4-14.
// Определите swap(t,x,y) в виде макроса, который осуществляет обмен значениями указанного 
// типа t между аргументами x и y. (Примените блочную структуру.)

#include <stdio.h>

// #define swap(t,x,y) t t##tmp; t##tmp = x; x = y; y = t##tmp;
#define swap(t,x,y) { t tmp; tmp = x; x = y; y = tmp;}

// -------------------------------- Main --------------------------------
int main(void) {
    int n, m;
    n = 1;
    m = 5;
    printf("\nInteger interchange:\n");
    printf("Originally n = %d, m = %d\n", n, m);
    printf("Interchanging...\n");
    swap(int, n, m);
    printf("And now n = %d, m = %d\n", n, m);

    float x, y;
    x = 3.142;
    y = 2.718;

    printf("\nFloat interchange:\n");
    printf("Originally x = %f, y = %f\n", x, y);
    printf("Interchanging...\n");
    swap(float, x, y);
    printf("And now x = %f, y = %f\n", x, y);

    char c, d;
    c = 'a';
    d = 'z';
    printf("\nChar interchange:\n");
    printf("Originally c = %c, d = %c\n", c, d);
    printf("Interchanging...\n");
    swap(float, x, y);
    printf("And now c = %c, d = %c\n", c, d);
}

// ---------------------------------------------------------

