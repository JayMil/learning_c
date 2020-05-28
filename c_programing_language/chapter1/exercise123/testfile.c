
/*
 * Exercise 1-23 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 *  This is a test c file for removing comments
 */

#include <stdio.h>

// max value
#define MAX 10

#define MSG "My /* // msg /* //"


/* Main Function */
int main() {
    for(int i = 0; i < MAX; i++) { // loop until max
        printf("%s\n", MSG);
        printf("// Comment in string 1\n");
        printf("/* Comment in string 2 */\n");
    }

    return 0; /* Return Success */
}


