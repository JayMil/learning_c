/*
 * Exercise 2-01 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  Program that determines the ranges of char, short, int and long, 
 *  both signed and unsigned, by printing appropriate values from standard
 *  headers and by direct computation.
 *
 *  By Jake Milder
 */

#include <limits.h>
#include <stdio.h>

int main(void) {

    printf("%20s: %25d\n", "char min", CHAR_MIN);
    printf("%20s: %25d\n", "char max", CHAR_MAX);
    printf("%20s: %25d\n", "signed char min",  SCHAR_MIN);
    printf("%20s: %25d\n", "signed char max",  SCHAR_MAX);
    printf("%20s: %25u\n", "unsigned char max",  UCHAR_MAX);
    printf("%20s: %25d\n", "short min",  SHRT_MIN);
    printf("%20s: %25d\n", "short max",  SHRT_MAX);
    printf("%20s: %25u\n", "unsigned short max",  USHRT_MAX);
    printf("%20s: %25d\n", "int min",  INT_MIN);
    printf("%20s: %25d\n", "int max",  INT_MAX);
    printf("%20s: %25u\n", "unsigned int max",  UINT_MAX);
    printf("%20s: %25ld\n", "long min",  LONG_MIN);
    printf("%20s: %25ld\n", "long max",  LONG_MAX);
    printf("%20s: %25lu\n", "unsigned long max",  ULONG_MAX);

    return 0;
}
