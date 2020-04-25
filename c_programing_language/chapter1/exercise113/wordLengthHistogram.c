/*
 * Exercise 1-13 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Given input, display histogram of word lengths
 *
 */
#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

int main() {
    int c, i, wl, state, maxWordLength, maxHistWidth;
    maxWordLength = 10;
    int wordLengths[maxWordLength+1];


    // initialize variables
    maxHistWidth = 80;
    c = wl = 0;
    for (i = 0; i <= maxWordLength; i++)
        wordLengths[i] = 0;

    state = OUT;
    while (( c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                // end of word - add to wordLengths and reset wl
                if (wl >= maxWordLength)
                    wordLengths[maxWordLength] += 1;
                else
                    wordLengths[wl] += 1;
                wl = 0;
            }
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
        }
        if (state == IN) {
            wl++;
        }
    }


    printf("== Word Lengths Histogram ==\n");
    for (i = 0; i <= maxWordLength; i++) {
        if (i == maxWordLength)
            printf("Word Length +%2d: ", i);
        else
            printf("Word Length %3d: ", i);

        for (int j = 0; j < wordLengths[i] && j < maxHistWidth; j++)
            printf("█");

        printf("\n");
    }

    return 0;
}
