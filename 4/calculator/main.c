#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include "calc.h"

#define MAXOP 100  /* макс. размер операнда или оператора */

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    int len = 0;
    int pos = 0;
    double op2;
    char s[MAXOP];
    char word[MAXOP];

    //aa bb

    while ((len = get_line(s)) > 0) {
        int position = 0;
        while(position < len) {
            position = get_word(position, s, word);
            printf("%s ",word);
        }
    }
    return 0;
}