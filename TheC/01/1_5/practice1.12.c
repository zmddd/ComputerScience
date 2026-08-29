#include <stdio.h>
    #define IN 1
    #define OUT 0
// int main(void)
// {
//     int c,nl,nw,nc,state;

//     state = OUT;

//     nl = nw = nc = 0;
//     while(c = getchar() != EOF){
//         ++nc;
//         if (c =='\n');
//         ++nl;
//         if(c == ' ' || c == '\n' || c == '\t')
//             state = OUT;
//         if(state == OUT)
//         {
//             state = IN;
//             ++nw;
//         }
//     }
//     printf("%d %d %d\n",nl,nw,nc);
// }

int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            if (state == OUT) {
                state = IN;
            }
            putchar(c);
        }
    }

    if (state == IN) {
        putchar('\n');
    }

    return 0;
}