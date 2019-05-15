// Упражнение 1.22. Напишите программу, печатающую символы входного потока так, 
// чтобы строки текста не выходили правее n-й позиции. Это значит, что каждая строка, 
// длина которой превышает n, должна печататься с переносом на следующие строки. 
// Место переноса следует “искать” после последнего символа, отличного от символа-разделителя, 
// расположенного левее n-й позиции. Позаботьтесь о том, чтобы ваша программа вела себя разумно 
// в случае очень длинных строк, а также когда до n-й позиции не встречается ни одного 
// символа пробела или табуляции.

// Упражнение 1.22. Напишите программу, печатающую символы входного потока так, чтобы строки текста не выходили правее n-й позиции. Это значит, что каждая строка, длина которой превышает n, должна печататься с переносом на следующие строки. Место переноса следует “искать” после последнего символа, отличного от символа-разделителя, расположенного левее n-й позиции. Позаботьтесь о том, чтобы ваша программа вела себя разумно в случае очень длинных строк, а также когда до n-й позиции не встречается ни одного символа пробела или табуляции.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN 300
#define N 10

#define MIN(x,y)    ((x) < (y) ? (x) : (y))

// -------------------------------- Prototypes --------------------------------
int get_line(char[]);
void fold_line(char [], int, int);
void print_line_segment(char [], int, int);
// -------------------------------- Main --------------------------------
int main(void) {
    char s[MAX_LEN], t[MAX_LEN];
    int len;

    while((len = get_line(s)) > 0) {
        if (len < N)
            printf("%s\n",s);
        else {
            fold_line(s, len, N);
        }
    }
}


int get_line(char s[]) {
    int c, i = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

void fold_line(char s[], int len, int lim) {

    int start_pos = 0;

    while (true) {
        int final_pos = MIN(start_pos + lim - 1, len - 1);

        if (final_pos == len-1)
        {
            print_line_segment(s, start_pos, final_pos + 1);
            return;        
        }

        int pos = final_pos;
        while (s[pos] != ' ' && s[pos] != '\t' && pos >= start_pos)
            --pos;
        if (pos > start_pos)
            final_pos = pos + 1;
        else
            final_pos = N;

        print_line_segment(s, start_pos, final_pos);
        start_pos = final_pos;
    }
}


void print_line_segment(char s[], int start_pos, int final_pos) {
    for (int i = start_pos; i < final_pos; ++i)
        putchar(s[i]);      
    putchar('\n');
}