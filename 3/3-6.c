// Упражнение 3.6. Напишите версию itoa с дополнительным третьим аргументом, задающим минимальную ширину 
// поля. При необходимости преобразованное число должно слева дополняться пробелами.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 33

void itoa(int, char[], int);
void reverse(char[]);
int abs(int);

// -------------------------------- Main --------------------------------
int main(void) {

    char s[MAX_LEN];
    int n;

    printf("Enter a number:\n");
    scanf("%d", &n);

    itoa(n,s,8);

    printf("%s\n",s);

    return 0;
}

void itoa(int n, char s[], int width) {

    int sgn = 1;
    int i = 0;
    int digits = 0;

    if (n < 0) {
        sgn = -1;
        width -= 1;
    }

    do {
        s[i++] = '0' + abs(n % 10);
        n /= 10;
        digits += 1;
    } while(n != 0);

    if (sgn == -1)
        s[i++] = '-';

    for (; i < width; ++i)
        s[i] = ' ';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int abs(int n) {
    return n < 0 ? -n : n;
}