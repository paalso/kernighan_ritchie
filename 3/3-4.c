// Упражнение 3.4. При условии, что для представления чисел используется дополнительный код, 
// наша версия itoa не справляется с самым большим по модулю отрицательным числом, 
// значение которого равняется -2^(n-1), где n - размер слова. Объясните, чем это вызвано. 
// Модифицируйте программу таким образом, чтобы она давала правильное значение указанного числа 
// независимо от машины, на которой выполняется.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 33

void itoa(int, char[]);
void reverse(char[]);
int abs(int);

// -------------------------------- Main --------------------------------
int main(void) {

    char s[MAX_LEN];
    int n;

    printf("Enter a number:\n");
    scanf("%d", &n);

    itoa(n,s);

    printf("%s\n",s);

    return 0;
}

void itoa(int n, char s[]) {

    int sgn = 1;
    int i = 0;

    if (n < 0) {
        sgn = -1;
        // n = -n; // должны избавиться от этой операции т.к. - INT_MIN = INT_MAX выходит за пределы диапазона int
    }

    do {
        s[i++] = '0' + abs(n % 10);
        n /= 10;
    } while(n != 0);

    if (sgn == -1)
        s[i++] = '-';

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