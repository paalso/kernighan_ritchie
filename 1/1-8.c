// Упражнение 1.8. Напишите программу для подсчета пробелов, табуляций и новых строк.

#include <stdio.h>
#include <stdbool.h>

#define IN true
#define OUT false

int main(void)
{

    int c;
    int nc, nt, nb, nn, nw;
    bool state = OUT;
    float wl;
    nc = nt = nb = nn = nw = 0;

    printf("\nInput a text\n");

    while((c = getchar()) != EOF) {
        ++nc;
        
        switch (c) {
            case '\n': 
                ++nn; 
                state = OUT;
                break;
            case '\t':
                ++nt; 
                state = OUT;
                break;
            case ' ': 
                ++nb;
                state = OUT;
                break;
            default:
                if (state == OUT) {
                    ++nw;
                    state = IN;
                }
        }
    }

    wl = (nc - nb - nt - nn) / (1.0 * nw);

    printf("Info about a text\n");
    printf("---------------------\n");
    printf("words      %5d\n",nw);
    printf("symbols    %5d\n",nc);
    printf("new strings%5d\n",nn);
    printf("blanks     %5d\n",nb);
    printf("tabulations%5d\n",nt);
    printf("average word's length: %.1f\n", wl);

    return 0;
}