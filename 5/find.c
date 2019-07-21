#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define EXIT_ERR { fprintf(stderr, "Usage: find [-n] [-x] pattern\n"); return 1;}


int get_line(char *line, int max);
/* find: печать строк с образцом, заданным 1-м аргументом */
int main(int argc, char *argv[]) {

    const int min_params = 1;
    const int max_params = 3;

    if (argc > max_params + 1 || argc <= min_params) 
        EXIT_ERR

    int numer = 0;  // указывает на потребность в нумерации строк
    // служит признаком слова "кроме", 
    int exclude = 0;    // которое изменяет задание на противоположное
    // (*++argv)[0] == '-' : последовательно проверяем те 'слова', 
    // первый символ к-х '-' - это 'параметры'
    while (--argc && (*++argv)[0] == '-')
    {
        char c;
        // *++argv[0] : в найденных токенах - параметрах последовательно
        // проверяем символы (пока не достинем '0')
        while (c = *++argv[0]) {
            switch(c) {
                case 'n': numer = 1; break;
                case 'x': exclude = 1; break;
                default: 
                    printf("Incorrect parameter %c\n", c);
                    EXIT_ERR;
            }
        }
    }

    // Check!!!
    // printf("n = %d, x = %d\n",numer, exclude);
    // printf("%d\n",argc);
    // printf("%s\n",*argv);

    if (argc != 1)
        EXIT_ERR

    // то, что осталось, после обработки параметров - единственное слово -
    // образец для поиска
    char *needle = *argv;     
    
    // Поиск и вывод результатов
    int len;
    int found = 0;    // счетчик найденных (удовл-х параметрам) строк
    int strnum = 0;     // счетчик номеров всех прочитанных строк
    char s[MAXLINE];

    while((len = get_line(s, MAXLINE)) > 0) {
        strnum += 1;
        if ((strstr(s, needle) != NULL) != exclude) {
            if (numer)
                printf("%d: ",strnum);
            printf("%s\n", s);
            found += 1;
        }
    }
    printf("\nTotal: %d strings\n", strnum);
    printf("Found: %d strings\n", found);

    return 0;
}


// --- get_line ---------------------------------------------------------
// get_line: читает строку в s, возвращает длину
int get_line(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i] = '\0';
    return i;
}