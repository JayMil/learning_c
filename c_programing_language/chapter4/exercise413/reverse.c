/*
 * Exercise 4-13 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write a recursive version of the function reverse(s), which reverses the
 * string s in place
 *
 *  By Jake Milder
 */
#include <stdio.h>

int slen(char msg[]);

void sreverse(char msg[]);
void rreverse(char msg[], int len, int indexA, int indexB);
void swap(char msg[], int indexA, int indexB);

int main() {
    char msg[20] = "Hello World";
    printf("'%s'\n", msg);
    sreverse(msg);
    printf("'%s'\n", msg);

    return 0;
}

void sreverse(char msg[]) {
    int len = slen(msg);
    rreverse(msg, len, 0, len-1);
}

void rreverse(char msg[], int len, int indexA, int indexB) {

    // we hit the middle and no swap needed
    if (indexA == indexB) return; 

    // we hit the middle and a swap is needed
    if ((indexA + 1) == indexB) {
        swap(msg, indexA, indexB);
        return;
    } 

    rreverse(msg, len, indexA+1, indexB-1);
    swap(msg, indexA, indexB);
}

void swap(char msg[], int indexA, int indexB) {
    char temp = msg[indexA];
    msg[indexA] = msg[indexB];
    msg[indexB] = temp;
}
    

int slen(char msg[]) {
    int n = 0;
    while(msg[n++] != '\0') ;
    n--;
    return n;
}


