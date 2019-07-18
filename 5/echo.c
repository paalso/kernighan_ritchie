#include <stdio.h>

int main(int argc, char *argv[]) {
      
    while(--argc)
        printf("%s%s", *++argv, argc > 1 ? " " : "");

    return 0;
}