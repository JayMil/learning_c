/*
 * Exercise 2-02 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  Program to translate the following for loop to a loop without using && or ||
 *  for(i = 0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c;
 *
 *  By Jake Milder
 */

#include <stdio.h>

int readlineForLoop(char s[], int lim);
int readlineLoop(char s[], int lim);

#define MAX_LINE 1000


int main(void) {
    char s[MAX_LINE];
    int lim = MAX_LINE - 1;
    int len;

    for(int i = 0; (len = readlineLoop(s, lim)) != -1; i++) {
        printf("%3d:%3d %s\n", i, len, s);
    }

    return 0;
}

int readlineLoop(char s[], int lim) {
    char c;
    int i = 0;
    while(i < lim-1) {
        c = getchar();
        if(c == EOF)
            break;
        else if(c == '\n')
            break;
        else
            s[i++] = c;
    }

    s[i] = '\0';

    if(c == EOF && i == 0)
        return -1;

    return i;

}


int readlineForLoop(char s[], int lim) {
    char c;
    int i;
    for(i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] =  c;

    s[i] = '\0';

    if(c == EOF && i == 0)
        return -1;

    return i;

}
