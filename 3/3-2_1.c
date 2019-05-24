// Упражнение 3.2. Напишите функцию escape (s,t), которая при копировании текста 
// из t в s преобразует такие символы, как новая строка и табуляция в 
// "видимые последовательности символов" (вроде \n и \t). Используйте инструкцию switch. 
// Напишите функцию, выполняющую обратное преобразование эскейп- последовательностей в настоящие символы.


#include <stdio.h>

#define MAXLINE 1000

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
void escape(const char[], char[]);

// -------------------------------- Main --------------------------------
int main() {

    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a text:\n");
    while (getLine(s1) != 0) {
        escape(s1,s2);
        printf("%s", s2); 
    }
    return 0;
}


// -------------------------------- Functions --------------------------------
// Считывает строку
int getLine(char s[]) {
    int c, i = 0;

    while((c = getchar()) != EOF) {
        s[i++] = c;
        if (c == '\n')
            break;
    }
    s[i] = '\0';

    return i;
}

// escape
void escape(const char s[], char t[]) {
    char c;
    int i = 0;
    int j = 0;
    while((c = s[i++]) != EOF) {
        switch (c) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = c;
        }
    }
    t[j] = '\0';
}