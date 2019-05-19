// Упражнение 2.1. Напишите программу, которая будет выдавать диапазоны значений типов 
// char, short, int и long, описанных как signed и как unsigned, с помощью печати 
// соответствующих значений из стандартных заголовочных файлов и путем прямого вычисления. 
// Определите диапазоны чисел с плавающей точкой различных типов. Вычислить эти диапазоны сложнее.

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>


// -------------------------------- Main --------------------------------
int main(void)
{

    char c;
    short s;
    int i;   
    long l;
    long long ll;
    float f;
    double d;
    long double dl;

    long llong_max;

    // Explicit calculating of LONG_MAX, version № 1
    
    // long    prevN = SHRT_MAX - 1,
    //             n = SHRT_MAX,
    //             temp;

    // printf("Explicit calculating of LONG_MAX...\n");
    // while (n > 0) {    // while (n > 0)     while (n - prevN == 1)
    //     prevN = n++;
    // }
    // llong_max = prevN;


    long    prevN = SHRT_MAX + 1,
                n = prevN;

    printf("Explicit calculating of LONG_MAX...\n");
    printf("Calculating...\n");
    do {
        prevN = n;
        n = n * 2;
        // printf("Calculating: %ld    %ld\n",prevN,n );
    } while ((n / 2 == prevN));

    llong_max = (prevN - 1) * 2 + 1;
    printf("LONG_MAX = %ld\n",llong_max);


    printf("\n\nType                Size      Min value             Max value\n");
    printf("-------------------------------------------------------------------\n");

    printf("Сhar           %7d%22d%22d\n", sizeof(c), CHAR_MIN,CHAR_MAX);
    printf("Short          %7d%22d%22d\n", sizeof(s), SHRT_MIN,SHRT_MAX);
    printf("Short unsigned %7d%22d%22d\n", sizeof(s), 0,USHRT_MAX);
    printf("Int            %7i%22i%22i\n", sizeof(i), INT_MIN,INT_MAX);
    printf("Int unsigned   %7d%22i%22u\n", sizeof(i), 0,UINT_MAX);
    printf("Long           %7d%22li%22li\n", sizeof(l), LONG_MIN,LONG_MAX);
    printf("Long unsigned  %7d%22li%22lu\n", sizeof(l), 0,ULONG_MAX);
    printf("Long long      %7d\n", sizeof(ll));

    printf("\nLong long, min value:         %22lld%\n", LLONG_MIN);
    printf("Long long, max value:           %20lld%\n", LLONG_MAX);
    printf("Long long unsigned, max value:  %20llu%\n", ULLONG_MAX);

    printf("\n\n\nType   Size                       Epsilon              Max value\n");
    printf("----------------------------------------------------------------------\n");
    printf("Float  %3d       %.17f = %7e   %15e\n", sizeof(f), FLT_EPSILON, FLT_EPSILON, FLT_MAX);
    printf("Double %3d       %.17f = %7e  %15e\n", sizeof(d), DBL_EPSILON, DBL_EPSILON, DBL_MAX);

    // printf("Float\t\t%d\t%d\t\t%d\n", sizeof(f), SHRT_MIN,SHRT_MAX);
    // printf("Double\t\t%d\t%d\t\t%d\n", sizeof(d), SHRT_MIN,SHRT_MAX);
    // printf("Long Double\t\t%d\t%d\t\t%d\n", sizeof(dl), SHRT_MIN,SHRT_MAX);

    return 0;
}

// -------------------------------- Functions --------------------------------