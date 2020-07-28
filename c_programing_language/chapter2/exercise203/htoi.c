/*
 * Exercise 2-03 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  Create a function htoi(s) that converts a string of hexadecimal digits
 *  (including 0x or OX) into its equivalent integer value. 
 *  The allowed digits are 0-9, a through f, and A through F.
 *
 *  By Jake Milder
 */

#include <stdio.h>

int htoi(char s[]);
int isUpperAlphaHex(char c);
int isLowerAlphaHex(char c);
int isNum(char c);
int isHex(char c);

int main(void) {

    printf("%d\n", htoi("AAx"));

    return 0;
}

int htoi(char s[]) {
    int n = 0;

    for(int i=0; isHex(s[i]); ++i) {
        if(isUpperAlphaHex(s[i])) {
            n = 16 * n + (10 + (s[i] - 'A'));
        } else if(isLowerAlphaHex(s[i])) {
            n = 16 * n + (10 + (s[i] - 'a'));
        } else { //isNum
            n = 16 * n + (s[i] - '0');
        }
    }
    return n;
}

int isUpperAlphaHex(char c) {
    return c >= 'A' && c <= 'F';
}

int isLowerAlphaHex(char c) {
    return c >= 'a' && c <= 'f';
}

int isNum(char c) {
    return c >= '0' && c <= '9';
}

int isHex(char c) {
    return     (isUpperAlphaHex(c))
            || (isLowerAlphaHex(c))
            || (isNum(c));
}
    
