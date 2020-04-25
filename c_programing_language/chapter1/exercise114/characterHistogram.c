/*
 * Exercise 1-14 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Given input, display histogram of characters
 *
 */
#include <stdio.h>

#define ALPHA_CHARACTERS    25  /* A-Z (25) */
#define NUM_CHARACTERS      10  /* 0-9 (10) */
#define OTHER_CHARACTERS    4   /* spaces(1), tabs(1), newlines(1), Other(1) */
#define MAX_HIST_WIDTH 80

int main() {
    int c, i, j;
    int alphas[ALPHA_CHARACTERS+1];
    int nums[NUM_CHARACTERS+1];
    int others[OTHER_CHARACTERS+1];


    // initialize variables
    for (i = 0; i <= ALPHA_CHARACTERS; i++)
        alphas[i] = 0;
    for (i = 0; i <= NUM_CHARACTERS; i++)
        nums[i] = 0;
    for (i = 0; i <= OTHER_CHARACTERS; i++)
        others[i] = 0;

    while (( c = getchar()) != EOF) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            // Don't track upper and lower case, just covert lower to upper case
            if (c >= 'a')
                c -= 32;

            alphas[c - 'A']++;
        } else if(c >= '0' && c <= '9') {
            nums[c - '0']++;
        } else if(c == ' ') {
            others[0]++;
        } else if(c == '\t') {
            others[1]++;
        } else if(c == '\n') {
            others[2]++;
        } else {
            others[3]++;
        }
    }


    printf("== Character Histogram ==\n");
    // print alpha characters
    for (i = 0; i <= ALPHA_CHARACTERS; i++) {
        printf("%7c: ", (i+'A'));

        for (j = 0; j < alphas[i] && j < MAX_HIST_WIDTH; j++)
            printf("█");

        printf("\n");
    }
    // print num characters
    for (i = 0; i < NUM_CHARACTERS; i++) {
        printf("%7d: ", i);
        for (j = 0; j < nums[i] && j < MAX_HIST_WIDTH; j++)
            printf("█");
        printf("\n");
    }
    // print other characters
    for (i = 0; i < OTHER_CHARACTERS; i++) {
        if (i == 0)
            printf("  space: ");
        else if (i == 1)
            printf("    tab: ");
        else if (i == 2)
            printf("newline: ");
        else
            printf("  other: ");

        for (j = 0; j < others[i] && j < MAX_HIST_WIDTH; j++)
            printf("█");

        printf("\n");
    }

    return 0;
}
