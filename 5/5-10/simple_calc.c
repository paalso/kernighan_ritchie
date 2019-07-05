// Сделано в тестовых целях - для анализа проблемы с символом '*'
// Проблема заключается в том, что в режиме работы в командной строке
// символ '*' имеет, по-видимому, какой то предопределенный в ОС смысл, 
// что не позволяет его считывать и использовать как произвольный символ

#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <string.h> /* для strcmp */

#define MAXLINE 100

// --- main -----------------------------------------
int main(int argc, char* argv[]) {

    float operand1 = atof(argv[1]);
    float operand2 = atof(argv[3]);
    float result;

    char op = argv[2][0];

    switch (op) {
        case '+' : result = operand1 + operand2; break;
        case '*' : result = operand1 * operand2; break;
        case '-' : result = operand1 - operand2; break;
        case '/' : result = operand1 / operand2; break;
        default: 
            printf("Error: incorrect operation %s\n", argv[2]);
            printf("Usage: number1 operation(+, *, -, /) number2"); 
            return 1;
    }
    printf("%f\n",result);
    return 0;
}