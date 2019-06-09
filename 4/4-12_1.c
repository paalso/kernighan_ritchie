// Упражнение 4.12. Примените идеи, которые мы использовали в printd, 
// для написания рекурсивной версии функции itoa; иначе говоря, 
// преобразуйте целое число в строку цифр с помощью рекурсивной программы. 

#include <stdio.h>
#include <string.h>

void itoa(int, char[]);
int itoa_segment(int, char[]);
void shift_str(char[]);

void printd(int);
void reverse(char[]);

// -------------------------------- Main --------------------------------
int main(void) {

    int n;
    char str[20];
    str[0] = '\0';
    printf("Number: ");
    scanf("%d", &n);

    itoa(n, str);
    printf("String:\n%s", str);
}

// ---------------------------------------------------------

void itoa(int n, char s[]) {
    static int sgn = 1;
    static int digits = 0;

    if (n < 0) {
        n = -n;
        sgn = -1;
    }

    if (n == 0) {
        if (digits == 0)
            strcpy(s, "0");
        else if (sgn == -1) {
            shift_str(s);
            s[0] = '-';
        }
        return;
    }

    shift_str(s);
    s[0] = '0' + n % 10;

    digits += 1;
    itoa(n / 10, s);  
}

void shift_str(char s[]) {
    int i = strlen(s);
    s[i + 1] = '\0';
    for (; i > 0; --i)
        s[i] = s[i - 1];
}