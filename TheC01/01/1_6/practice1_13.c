#include <stdio.h>

int main(void) {
    int c, i, j;
    int len = 0;
    int counts[11] = {0};

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
            if (len > 0) {
                if (len > 10) {
                    len = 10;
                }
                counts[len]++;
                len = 0;
            }
        } else {
            len++;
        }
    }

    if (len > 0) {
        if (len > 10) {
            len = 10;
        }
        counts[len]++;
    }

    for (i = 1; i <= 10; ++i) {
        printf("%d: ", i);
        for (j = 0; j < counts[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
