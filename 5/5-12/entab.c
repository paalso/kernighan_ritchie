// Упражнение 1.21. Напишите программу entab, заменяющую строки из пробелов 
// минимальным числом табуляций и пробелов таким образом, чтобы вид напечатанного 
// текста не изменился. Используйте те же “стопы” табуляции, что и в detab. 
// В случае, когда для выхода на очередной “стоп” годится один пробел, что лучше - пробел или табуляция?


// 012345678901234567890
// I**********Love***You
// I--***Love-**You

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN 100
#define TAB_POS 8

#define MAX(x,y)    ((x) > (y) ? (x) : (y))


// -------------------------------- Prototypes --------------------------------
int get_line(char[]);
void entab(const char[], char[]);

// -------------------------------- Main --------------------------------
int main(void) {
    char s[MAX_LEN], t[MAX_LEN];

    printf("Start!\n");

    while(get_line(s) > 0) {
        entab(s,t);
        printf("%s\n",t);
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

void entab(const char from[], char to[]) {
    int c, i = 0, j = 0;
    while((c = from[i]) != '\0') {
        if (c == ' ')
        {
            int count_blancs = 1;
            while((c = from[i + count_blancs]) == ' ')
                count_blancs += 1;
            if (count_blancs > 1)    // && i + count_blancs > TAB_POS
            {
                int next_position = i + count_blancs;
                int last_tab_position = (next_position / TAB_POS) * TAB_POS;
                int tabs_count = next_position / TAB_POS - (i + TAB_POS) / TAB_POS + 1;
                int extra_blancs_count = next_position - MAX(last_tab_position, i);
                for (int k = 0; k < tabs_count; ++k)
                    to[j++] = '\t';
                for (int k = 0; k < extra_blancs_count; ++k)
                    to[j++] = ' ';
                i = next_position;
            }
        }
        to[j++] = from[i++];
    }
    to[j] = '\0';
}
