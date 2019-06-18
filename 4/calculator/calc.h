#define NUMBER 0
#define MATH_OP 1
#define MATH_FUN 2
#define STACK_OP 3
#define VAR 4
#define ERR 5

void push (double);
double pop (void);
double take (void);
void print_stack(void);

_Bool is_number(char []);
int getop (char []);

int getch(void);
int get_line();
int get_word(int, char[], char[]);
void ungetch(int);