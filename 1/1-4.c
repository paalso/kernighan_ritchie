/* Упражнение 1.3. Усовершенствуйте программу преобразования температур таким образом, 
чтобы над таблицей она печатала заголовок.

Упражнение 1.4. Напишите программу, которая будет печатать таблицу соответствия
температур по Цельсию температурам по Фаренгейту.
*/
#include <stdio.h>

int main(void)
{

    float fahr, celsius;
    float lower = 0;
    float upper = 300;
    float gap = 100;
    float step_lower = 10;
    float step_upper = 20;
    float step = step_lower;

    celsius = lower;
    printf("Celsius to Fahrenheit conversion\n\n");
    printf("celsius  fahrenheit\n\n");

    while (celsius <= upper) {
        if (celsius >= gap) {
            step = step_upper;
        }
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%5.0f%11.1f\n", celsius, fahr );
        celsius += step;
    }

    return 0;
}