#include <stdio.h>
int temperature(int f);

int main()
{

    /* Print a simple header */
    int fahr, celsius, step;
    int lower, upper;
    lower = 0;   /* lower limit of the table */
    step = 20;
    upper = 300; /* upper limit of the table */
    fahr = lower;

    while (fahr <= upper)
    {
        celsius = fahr_to_celsius(fahr);
        printf("%d %d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

int fahr_to_celsius(int f)
{
    int c;
    c = 5 * (f - 32) / 9;
    return c;
}