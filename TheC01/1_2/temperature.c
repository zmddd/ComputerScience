#include <stdio.h>
int main()
{
    /* Print a simple header */
    printf("%s\n", "Fahrenheit to Celsius");
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;   /* lower limit of the table */
    upper = 300; /* upper limit of the table */
    step = 20;   /* step size */
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}