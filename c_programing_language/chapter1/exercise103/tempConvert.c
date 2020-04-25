/*
 * Exercise 1-03 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 */
#include <stdio.h>



/* 
 * print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 */
int main() {
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("\n\n== Fahrenheit to Celsius ==\n");
    printf("%10s%12s", "Fahrenheit", "Celsius\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f%11.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}


