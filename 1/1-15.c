/* Упражнение 1.15. Перепишите программу преобразования температур, 
выделив само преобразование в отдельную функцию.Упражнение 1.15. 
Перепишите программу преобразования температур, выделив само преобразование в отдельную функцию.
*/
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr(float);

int main(void)
{

    printf("Celsius to Fahrenheit conversion\n\n");
    printf("celsius  fahrenheit\n\n");

    for (int celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        printf("%5d%11.1f\n", celsius, fahr(celsius));
    }
    return 0;
}

float fahr(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}