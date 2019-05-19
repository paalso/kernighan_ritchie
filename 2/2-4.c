// Упражнение 2.4. Напишите версию функции squeeze(s1,s2), 
// которая удаляет из s1 все символы, встречающиеся в строке s2.


#include <stdio.h>

#define MAXLINE 1000

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
void squeeze(char[], const char[]);

// -------------------------------- Main --------------------------------
int main() {

    char s1[MAXLINE], s2[MAXLINE];
    char c;

    printf("Input a string:\n");
    getLine(s1);
    printf("Input another one:\n");
    getLine(s2);
    squeeze(s1,s2);
    printf("Squeezed string:\n",s1);
    printf("%s\n",s1);
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

// squeeze
void squeeze(char s[], const char t[]) {
    for (int k = 0; t[k] != '\0'; ++k) {
        int i, j;
        char c = t[k];
        for (i = j = 0; s[i] != '\0'; ++i) {
            if (s[i] != c)
                s[j++] = s[i];
        }
        s[j] = '\0';
    }
}