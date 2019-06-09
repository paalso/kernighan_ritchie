// Упражнение 4.12. Примените идеи, которые мы использовали в printd, 
// для написания рекурсивной версии функции itoa; иначе говоря, 
// преобразуйте целое число в строку цифр с помощью рекурсивной программы. 


#include <stdio.h>
#include <string.h>

void itoa(int, char[]);
void addsmbl(char[], char);

int main(void)
{   
    int n;
    char s[10];

    printf("Input a number: ");
    scanf("%d",&n);
    
    itoa(n, s);

    printf("%s", s);

    return 0;
}

// itoa: рекурсивная версия
void itoa(int n, char s[]) {

    if (n < 0){
        s[0] = '-';
        s[1] = '\0';
        n = - n;
    }

    if (n / 10)
        itoa(n / 10,s);
    addsmbl(s, '0' + n % 10);
}

// addsmbl : дописывает к строке str символ с
void addsmbl(char str[], char c) {
    int len = strlen(str);
    str[len++] = c;
    str[len] = '\0';
}