// Упражнение 3.2. Напишите функцию escape (s,t), которая при копировании текста 
// из t в s преобразует такие символы, как новая строка и табуляция в 
// "видимые последовательности символов" (вроде \n и \t). Используйте инструкцию switch. 
// Напишите функцию, выполняющую обратное преобразование эскейп- последовательностей в настоящие символы.


#include <stdio.h>

#define MAXLINE 1000

// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
void descape(const char[], char[]);

// -------------------------------- Main --------------------------------
int main() {

    char s1[MAXLINE], s2[MAXLINE];

    printf("Input a text:\n");
    while (getLine(s1) != 0) {
        descape(s1,s2);
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
void descape(const char s[], char t[]) {
    char c;
    int i = 0;
    int j = 0;
    while((c = s[i++]) != EOF) {
        if (c == '\\') {
            c = s[i++];
            switch (c) {
            case 't':
                t[j++] = '\t';
                break;
            case 'n':
                t[j++] = '\n';
                break;
            default :
                t[j++] = '\\';
                i--;
            }
        } else {
            t[j++] = c;
        }

    }
    t[j] = '\0';
}