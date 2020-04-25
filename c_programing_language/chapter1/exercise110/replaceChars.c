/*
 * Exercise 1-10 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Given input, replace tabs with \t, blankspace with \b and backslashes with \\
 * This makes tabs and blankspaces visible in an unambiguous way
 */

#include <stdio.h>

int main() {
    printf("== Replace Chars ==\n");
    int c = 0;

    while ( (c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
    return 0;
}
