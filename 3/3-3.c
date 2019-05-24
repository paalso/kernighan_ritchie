// Упражнение 3.3. Напишите функцию expand(s1,s2), заменяющую сокращенную запись наподобие a-z в строке s1 
// эквивалентной полной записью аbс...хуz в s2. В s1 допускаются буквы (прописные и строчные) и цифры. 
// Следует уметь справляться с такими случаями, как a-b-c, a-z0-9 и -a-b. Считайте знак - в начале или в конце s1 
// обычным символом минус.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 100

void expand(char[], char[]);
bool issamecase(char, char);

// -------------------------------- Main --------------------------------
int main(void) {

    char s[MAX_LEN], s1[MAX_LEN];

    printf("Enter a string:\n");
    // scanf("%s",s);
    gets(s);

    expand(s,s1);

    printf("%s\n",s1);

    return 0;
}

// -----------------------------------------------------------------------
void expand(char s[], char t[]) {
    // for (int i = 1; (c = s[i]) != '\0'; ++i) {
    char c;
    int i = 1;
    int j = 1;
    t[0] = s[0];
    while((c = s[i]) != '\0') {
        if (c == '-')
        {
            ++i;
            if (s[i] == '\0') {
                t[j++] = s[i - 1];
                break;
            }

            c = s[i];
            if ((isalpha(c) || isdigit(c)) && issamecase(c, s[i - 2]) && c > s[i - 2])
                for (int k = 1, len = c - s[i - 2]; k < len; ++k, ++j)
                    t[j] = s[i - 2] + k;
            else
                t[j++] = s[i - 1];
        } else
            t[j++] = s[i++];

    }
    t[j] = '\0';
}

// -----------------------------------------------------------------------
bool issamecase(char c1, char c2) {
    if ((isupper(c1) && isupper(c2) || (islower(c1) && islower(c2)) || (isdigit(c1) && isdigit(c2))))
        return true;
    return false;
}