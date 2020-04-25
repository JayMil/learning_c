/*
 * Exercise 1-09 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 *  Given input, replace any blanks of one to many with a single blank
 */

#include <stdio.h>

int main() {
    int c, prevC;
    c = prevC = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (prevC != ' ') {
                putchar(c);
            }
        } else {
            putchar(c);
        }
        prevC = c;
    }

    printf("\n");
    return 0;
}
