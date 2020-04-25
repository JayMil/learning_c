/*
 * Exercise 1-07 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 */
#include <stdio.h>


/* 
 * Verify getchar() != EOF returns 0 or 1 and print EOF value
 */
int main() {
    int c = 0;

    while ((c = getchar()) != EOF) {
        printf("char: %c - EOF: %d\n", c, (c != EOF));
    }
    printf("char: %c - EOF: %d\n", c, (c != EOF));
    return 0;
}


