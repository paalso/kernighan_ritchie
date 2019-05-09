// Упражнение 1.21. Напишите программу entab, заменяющую строки из пробелов 
// минимальным числом табуляций и пробелов таким образом, чтобы вид напечатанного 
// текста не изменился. Используйте те же “стопы” табуляции, что и в detab. 
// В случае, когда для выхода на очередной “стоп” годится один пробел, что лучше - пробел или табуляция?

#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 1000
#define TAB_POS 8


// -------------------------------- Prototypes --------------------------------
int getLine(char[]);
void entab(const char[], char[]);

// -------------------------------- Main --------------------------------
int main(void)
{

    int len;
    char str1[MAX_LEN], str2[MAX_LEN];

    while ((len = getLine(str1)) > 0) {
        entab(str1,str2);
        printf("%s",str1);
        printf("\n---------------------------------------\n\n");
        printf("%s",str2);
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

// ---------------------------
// Обработка считанной в in[] строки, результат - в out[]
void entab(const char in[], char out[]) {
    int c, cPrev = '\0';
    int i = 0, j = 0; // два счетчика индексов - для входной и результирующей строк отдельно
    int counter = 1;

    while ((c = in[i++]) != '\0') {

        if (c == ' ' && c == cPrev) {
            ++counter;
            cPrev = c;
            continue;
        } else if (counter > 1) {
            // int nextTabPos = ((j + TAB_POS) / TAB_POS) * TAB_POS;
            int lastTabPos = i / TAB_POS;
            int firstBlankPos = i - counter;
            int k = firstBlankPos;
            while (k < lastTabPos) {
                out[j] = '\t';
                j++;
                k += TAB_POS;
            }
            k = TAB_POS;
            while (k < i) {
                out[j] = ' ';
                j++;
                k++;
            }
            counter = 1;
        }

        out[j++] = c;
        cPrev = c;
        counter = 1;

    }
    out[j] = '\0';
}