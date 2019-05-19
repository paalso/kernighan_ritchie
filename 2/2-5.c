// Упражнение 2.5. Напишите функцию any(s1,s2), которая возвращает либо ту позицию в s1, 
// где стоит первый символ, совпавший с любым из символов в s2, либо -1 (если ни один символ 
//     из s1 не совпадает с символами из s2). (Стандартная библиотечная функция strpbrk 
//     делает то же самое, но выдает не номер позиции символа, а указатель на символ.)


#include <stdio.h>

#define MAXLINE 100

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
int any(char[], const char[]);
int findchar(const char[], const char);

// -------------------------------- Main --------------------------------
int main() {

    char s1[MAXLINE], s2[MAXLINE];
    char c;

    printf("Input a string:\n");
    getLine(s1);
    printf("Input another one:\n");
    getLine(s2);
    printf("position: %d\n",any(s1,s2));
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

// any
int any(char s[], const char t[]) {
    int position = -1;
    for (int i = 0; t[i] != '\0'; ++i) {
        for (int j = 0; s[j] != '\0'; ++j) {
            if (s[j] == t[i])
                return j;
        }
    }
    return -1;
}