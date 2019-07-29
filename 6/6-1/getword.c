#include <ctype.h>
#include <stdio.h>

int getch();
void ungetch(int);

int isallowedsymbol(char, const char*);
const char *allowed_symbols = "_/*0123456789";
const char *allowed_start_symbols = "_#/*";

// В целях более тонкой обработки "знаков подчеркивания" и пр.
// чуть изменим исходную функцию getword, добавив вспомогательную
// функцию isallowedsymbol, к-я определяет "допустимые символы" как
// литеры + символы из дополнительно передаваемого списка.
// Хотя и if (isalpha(symbol)) return 1 можно убрать и работать
// исключительно со списками разрешеннеых символов.
// Еще, по-хорошему, чтобы не привязывать списки типа *allowed_symbols к 
// данному файлу и максимально обобщить функцию getword, можно было бы добавить
// к сигнатуре функции дополнительно параметры, подразумевающие передачу этих списков,
// но это слишком сложно

int getword(char *word, int lim) {
    char *w = word;
    int c;

    // while ((c = getch()) == ' ' || c == '\t')
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    if (!isallowedsymbol(c, allowed_start_symbols)) {
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++) {
        if (! isallowedsymbol(*w = getch(), allowed_symbols)) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}


int isallowedsymbol(char symbol, const char *allowed_symbols) {
    char *c = allowed_symbols;
    while(*c)
        if(*c++ == symbol)
            return 1;
    if (isalpha(symbol))
        return 1;
    return 0;
}