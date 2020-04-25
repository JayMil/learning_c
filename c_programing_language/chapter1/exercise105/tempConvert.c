/*
 * Exercise 1-05 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 */
#include <stdio.h>


/* 
 * print Fahrenheit-Celsius table
 * for fahr = 300, 280, ..., 0
 */
int main() {
    printf("\n\n== Fahrenheit to Celsius - Hight to Low ==\n");
    printf("%10s%12s", "Fahrenheit", "Celsius\n");
    for(float lower = 300; lower >= 0; lower -= 20) {
        printf("%10.0f%11.1f\n", lower, (5.0/9.0) * (lower-32));
    }
    return 0;
}


