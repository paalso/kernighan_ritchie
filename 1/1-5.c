// Упражнение 1.5. Измените программу преобразования температур так, 
// чтобы она печатала таблицу в обратном порядке, т. е. от 300 до 0.

#include <stdio.h>

#define UPPER 300
#define LOW 0
#define STEP 20


int main(void)
{

    float celsius, fahr;
    printf("Celsius to Fahrenheit conversion\n\n");
    printf("celsius  fahrenheit\n\n");

    for (celsius = UPPER; celsius >= LOW; celsius -= STEP) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%5.0f%11.1f\n", celsius, fahr );
    }

    return 0;
}