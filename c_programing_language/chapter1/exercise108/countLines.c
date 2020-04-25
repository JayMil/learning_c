/*
 * Exercise 1-08 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 */

/*
 * Count blanks, tabs and newlines
 */ 

#include <stdio.h>

int main() {
    printf("== Count Lines ==\n");

    int c, nl, space, tab;
    c = nl = space = tab = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++tab;
        else if (c == ' ')
            ++space;
    }

    printf("Lines: %d\n", nl);
    printf("Tabs: %d\n", tab);
    printf("Spaces: %d\n", space);
    return 0;
}
