/*
 * Exercise 5-05 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write versions of the library functions strcpyn, strcatn and strcmpn,
 * which operate on at most the first n characters of their argument strings.
 * For example, strcpyn(s,t,n) copies at most n characters of t to s.
 *
 * Implementations of strcpyn, strcatn and strcmpn
 *
 *  By Jake Milder
 */

#include <stdio.h>
#include "modules.h"

void strcpyn(char *s, const char *t, int n) {
    for( ; n > 0 && (*s++ = *t++) != '\0'; n--)
        ;
}

void strcatn(char *s, const char *t, int n) {
    for( ; *s !='\0' ; s++)
        ;

    while(n-- > 0 && (*s++ = *t++) != '\0')
        ;

    *s = '\0';
}


int strcmpn(const char *s, const char *t, int n) {
    for( ; *s == *t && n > 0; s++, t++, n--) {
        if (*s == '\0' || n == 1)
            return 0;
    }

    if((*s - *t) < 0)
        return -1;
    else
        return 1;
}

int str_cmp(const char *s, const char *t) {
    for( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;

    if((*s - *t) < 0)
        return -1;
    else
        return 1;
}


