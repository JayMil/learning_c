/*
 * Exercise 5-03 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 *
 *  By Jake Milder
 */

#include <stdio.h>

#define BUF 100

// copy string t to the end of string s
void str_cat(char *s, char *t);

int main(void) {
    char s[BUF] = "hello";
    char t[BUF] = " world";
    str_cat(s, t);
    printf("%s", s);
}

void str_cat(char *s, char *t) {

    // move s pointer to end
    while(*s) 
        s++;


    while((*s++ = *t++))
        ;

}




