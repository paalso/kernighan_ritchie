#define NUMBER 0
#define MATH_OP 1
#define ERR 6

int get_line(char[], int);

double pop(void);
void push(double);
double top(void);

_Bool is_number(char []);
int getop (char []);