// Упражнение 2.10. Напишите функцию lower, которая переводит большие буквы в малые, 
// используя условное выражение (а не конструкцию if-else).


#include <stdio.h>

#define MAXLINE 1000

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
int lower(const char);
int strToLower(char[]);

// -------------------------------- Main --------------------------------
int main() {

    char s[MAXLINE];

    printf("Input a string:\n");
    getLine(s);
    strToLower(s);
    printf("%s\n",s);
    return 0;
}


// -------------------------------- Functions --------------------------------
// Считывает строку
int getLine(char s[]) {
    int c, i = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// lower
int lower(const char c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; 
}

int strToLower(char s[]) {
    char c;
    int i = 0;

    while ((c = s[i]) != '\0') {
        s[i++] = lower(c);
    }
}