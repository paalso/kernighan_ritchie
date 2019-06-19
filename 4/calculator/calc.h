#define NUMBER 0
#define MATH_OP 1
#define MATH_FUN 2
#define STACK_OP 3
#define VAR 4
#define COMMAND 5
#define ERR 6

double double_top(void);
void clear(void);
void inv(void);
void print_stack(void);
double pop(void);
void push(double);
double top(void);


_Bool is_number(char []);
int getop (char []);

int getch(void);
int get_line();
int get_word(int, char[], char[]);
void ungetch(int);