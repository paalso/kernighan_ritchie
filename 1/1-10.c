/*Упражнение 1.10. Напишите программу, копирующую вводимые символы в выходной поток 
с заменой символа табуляции на \t, символа забоя на \b и каждой обратной наклонной 
черты на \\. Это сделает видимыми все символы табуляции и забоя.
*/
#include <stdio.h>

int main(void)
{

    int c;

    printf("\nInput a text\n");

    while((c = getchar()) != EOF) {
        
        switch (c) {
            case '\b': 
                printf("\\b");
                break;
            case '\t':
                printf("\\t");
                break;
            case '\\': 
                printf("\\\\");
                break;
            default:
                putchar(c);
        }
    }

    return 0;
}