/*
 * Exercise 1-11 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Given input, print the number of newlines, words and characters
 * Test different input files
 *
 */

#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */


int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while (( c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}
