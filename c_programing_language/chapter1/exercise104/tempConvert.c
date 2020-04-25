/*
 * Exercise 1-04 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 */
#include <stdio.h>


/* 
 * print Celsius-Fahrenheit table
 * for fahr = 0, 20, ..., 300
 */
int main() {
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    printf("\n\n== Celsius to Fahrenheit ==\n");
    printf("%7s%15s\n", "Celsius", "Fahrenheit");
    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius)+32.0;
        printf("%7.0f%14.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}


