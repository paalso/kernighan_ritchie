// Упражнение  2.З.  Напишите  функцию  htoi(s),  которая  преобразует  последовательность 
// шестнадцатеричных цифр, начинающуюся с 0х или 0Х, в соответствующее целое. Шестнадцатеричными 
// цифрами являются символы 0…9, а…f, А…F.

#include <stdio.h>

#define MAXLINE 12

// -------------------------------- Prototypes --------------------------------
int get_line(char[]);
char lower(char);
long long htoi(const char[]);

// -------------------------------- Main --------------------------------
int main() {

    char s[MAXLINE];
    long long n;

    printf("Input a string of hexadecimal digits (including an optional 0x or 0X):\n");
    get_line(s);
    n = htoi(s);
    printf("In decimal system it equals to %lli\n",n);
    return 0;
}


// -------------------------------- Functions --------------------------------
// Считывает строку
int get_line(char s[]) {
    int c, i = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}


long long htoi(const char s[]) {
    long long result = 0;
    long long exp = 1;
    int digit;
    char c;
    int len = 0;

    for (; (c = s[len]) != '\0'; ++len)
        ;
    for (int i = len - 1; i > 1; --i) {
        if ((c = s[i]) <= '9' && c >= '0')
            digit = c - '0';
        else
            digit = lower(c) - 'a' + 10;

        result += exp * digit;
        exp *= 16;
    }

    return result;
}


char lower(char c) {
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}