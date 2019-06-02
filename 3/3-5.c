// Упражнение 3.5. Напишите функцию itob(n,s,b), которая переводит целое n в строку s, 
// представляющую число по основанию b. В частности, itob(n, s, 16) помещает в s текст числа n 
// в шестнадцатеричном виде.


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 33

void itob(int, char[], int);
void reverse(char[]);
int abs(int);

// -------------------------------- Main --------------------------------
int main(void) {

    char s[MAX_LEN];
    int n, b;

    printf("Enter a number:\n");
    scanf("%d", &n);

    printf("Enter the numerical system base:\n");
    scanf("%d", &b);

    itob(n, s, b);

    printf("String:\n%s",s);

    return 0;
}

void itob(int n, char s[], int b) {

    int sgn = 1;
    int i = 0;

    if (n < 0) {
        sgn = -1;
    }

    do {
        int digit = abs(n % b);
        s[i++] = digit <= 9 ? '0' + digit : digit - 10 + 'a';
        n /= b;
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