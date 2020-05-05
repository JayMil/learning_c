/*
 * Exercise 1-17 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 *  Given input, print lines longer than 80 characters
 *  Note max width is 1000 characters, anything longer will be truncated
 *
 */
#include <stdio.h>

#define MAX_LINE 1000

int readline(char s[], int lim);

int main() {
    int lineLength;
    char letters[MAX_LINE];

    while((lineLength = readline(letters, MAX_LINE)) > 0) {
        if(lineLength > 80) {
            printf("%d: %s", lineLength, letters);
        }
    }
}

/* get line:    read a line into s, return length */
int readline(char s[], int lim) {
    // reserve memeory for character and index
    int c, i;

    // get characters until end of file or a new line
    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
        // if i is below the limit set index of i to character
        if (i<lim-1)
            s[i] = c;

    // if character is newline add it to char array
    if (c == '\n') {
        s[i] = c;
        i++;
    }

    // set last index to end sequence character
    s[i] = '\0';

    //return length
    return i;
}
