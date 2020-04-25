/*
 * Exercise 1-12 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Given input, print each word on a separate line
 * Test different input files
 *
 */

#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */


int main() {
    int c, state;

    state = OUT;
    while (( c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
            }
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
        }
        if (state == IN) {
            putchar(c);
        }
    }
    return 0;
}
