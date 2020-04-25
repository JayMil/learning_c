/*
 * Exercise 1-15 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 */
#include <stdio.h>

#define LOWER   0      /* lower limit of temperature table */
#define UPPER   300    /* upper limit */
#define STEP    20     /* step size */


float tempConvertFtoC(float fahr);

/* 
 * print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 */
int main() {
    float fahr;
    
    fahr = LOWER;
    printf("\n\n== Fahrenheit to Celsius ==\n");
    printf("%10s%12s", "Fahrenheit", "Celsius\n");
    while (fahr <= UPPER) {
        printf("%10.0f%11.1f\n", fahr, tempConvertFtoC(fahr));
        fahr+=STEP;
    }
    return 0;
}

float tempConvertFtoC(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}


