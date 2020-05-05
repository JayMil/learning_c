/*
 * Exercise 1-19 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Reverse the given input lines
 * Note max length of a line can be 1000 chars
 *
 */


#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int readline(char s[], int limit);
void reverse(char in[], char out[], int length);

int main() {
    int lineLength;
    char line[MAX_LINE_LENGTH];
    char reversed[MAX_LINE_LENGTH];


    while((lineLength = readline(line, MAX_LINE_LENGTH)) > 0) {
        reverse(line, reversed, lineLength);
        printf("%d: %s", lineLength, reversed);
    }

    return 0;
}

int readline(char s[], int limit) {
    int i, c;

    for(i = 0; i < limit -1 && ((c = getchar()) != EOF) && c != '\n'; i++) {
        s[i] = c;
    }

    // add new line char if found
    if(c == '\n') {
        s[i] = c;
        i++;
    }

    // end char array
    s[i]  = '\0';

    return i;
}

/* reverse line, but don't revese new lines */
void reverse(char in[], char out[], int length) {
    int i, j, copyLength;

    j = length;
    while(in[j] == '\n' || in[j] == '\0') {
        out[j] = in[j];
        j--;
    }

    copyLength = j;
    for(i = 0; i <= copyLength; i++, j--) {
        out[i] = in[j];
    }
}

