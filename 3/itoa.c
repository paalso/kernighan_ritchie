#include <stdio.h>
#include <string.h>

void itoa(int, char[]);
void reverse(char[]);

// -------------------------------- Main --------------------------------
int main(void) {
    int n;
    char str[20];
    printf("Number: ");
    scanf("%d", &n);
    itoa(n, str);
    printf("String:\n%s", str);
}

// ---------------------------------------------------------

void itoa(int n, char s[]) {
    char i = 0;
    int sgn;
    if ((sgn = n) < 0)
        n = - n;

    do {
        s[i++] = (n % 10) + '0';
    } while((n /= 10) > 0);
    if (sgn < 0)
        s[i++] = '-'; 
    s[i] = '\0';
    reverse(s);
}

// ---------------------------------------------------------
void reverse(char s[]) {
    char tmp;
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
        tmp = s[i], s[i] = s[j], s[j] = tmp;
    
}