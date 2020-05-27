/*
 * Exercise 1-21 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Replace four spaces with a tab
 *
 */

#include <stdio.h>

#define SPACE_COUNT 4

int main() {
    char c;
    int spaceCount = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            spaceCount++;
            if(spaceCount == SPACE_COUNT) {
                putchar('\t');
                spaceCount = 0;
            }
        } else {
            // print spaces that didn't amount to a tab
            while(spaceCount > 0) {
                putchar(' ');
                spaceCount--;
            }
            putchar(c);
        }
    }

    return 0;
}
