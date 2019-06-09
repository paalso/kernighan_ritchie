// Упражнение 4-13.
// Напишите рекурсивный вариант функции reverse(s), которая располагает в обратном порядке строку s.

#include <stdio.h>
#include <string.h>

void reverse(char[]);
void reverse_segment(char[], int, int);

// -------------------------------- Main --------------------------------
int main(void) {
    int n;
    char str[20];
    printf("Input a string:\n");
    scanf("%s", str);

    reverse(str);
    printf("Reversed string:\n%s", str);
}

// ---------------------------------------------------------


void reverse_segment(char s[], int i, int j) {
    if (j <= i)
        return;
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
    reverse_segment(s, i + 1, j - 1);
}

void reverse(char s[]) {
    reverse_segment(s, 0, strlen(s) - 1);
}
