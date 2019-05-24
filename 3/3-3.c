// Упражнение 3.3. Напишите функцию expand(s1,s2), заменяющую сокращенную запись наподобие a-z в строке s1 
// эквивалентной полной записью аbс...хуz в s2. В s1 допускаются буквы (прописные и строчные) и цифры. 
// Следует уметь справляться с такими случаями, как a-b-c, a-z0-9 и -a-b. Считайте знак - в начале или в конце s1 
// обычным символом минус.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000
#define TAB_POS 8

void expand(char[], char[]);
void append(char[], char[]);
void generate_alphabetical_line(char, char, char[]);

// -------------------------------- Main --------------------------------
int main(void) {

    char s[MAX_LEN], s1[MAX_LEN];

    printf("Enter a string:\n");
    scanf("%s",s);

    expand(s,s1);

    printf("%s\n",s1);

    return 0;
}

