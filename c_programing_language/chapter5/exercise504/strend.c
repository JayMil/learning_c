/*
 * Exercise 5-04 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write the function strend(s,t), which returns 1 if the string t occurs
 * at the end of the string s, and zero otherwise
 *
 *  By Jake Milder
 */

#include <stdio.h>

#define BUF 100

// return 1 if string s ends with string t, otherwise return 0
int str_end(char *s, char *t);

// print expected result of test
void print_result(char *s, char *t, int result);

// test str_end
void test(char *s, char *t, int expected);

int main(void) {
    char a[BUF] = "hello world";
    char b[BUF] = "world";

    test(a, b, 1);


    char c[BUF] = "hello world";
    char d[BUF] = "hello";
    test(c, d, 0);

    char e[BUF] = "hello world hello";
    char f[BUF] = "hello";
    test(e, f, 1);

    char g[BUF] = "hello";
    char h[BUF] = "hello world hello";
    test(g, h, 0);
}

void test(char *s, char *t, int expected) {

    int result = str_end(s, t);
    if(expected == result) {
        printf("PASS: ");
    } else {
        printf("FAIL: ");
    }
    print_result(s, t, expected);
    printf("\n");
}

void print_result(char *s, char *t, int result) {
    if(result) {
        printf("String '%s' ends with '%s'", s, t);
    } else {
        printf("String '%s' does not ends with '%s'", s, t);
    }
}


int str_end(char *s, char *t) {
    // move pointers to end of each, counting the lengths
    int slen = 0;
    while(*s++)
        slen++;

    int tlen = 0;
    while(*t++)
        tlen++;

    if (slen > tlen) {
        // compare ends of strings up to length of string t
        while((*s-- == *t--) && --tlen > 0)
            ;

        return tlen == 0;
    }

    return 0;
}




