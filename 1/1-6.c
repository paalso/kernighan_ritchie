// Упражнение 1.6. Убедитесь в том, что выражение getchar() != EOF получает значение 0 или 1.

#include <stdio.h>

int main(void)
{

    int c;
    while((c = getchar()) != EOF)
        printf("%d", c != EOF);
    
    return 0;
}