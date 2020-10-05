/*
 * Exercise 2-05 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  Create a function any(s1, s2) which returns the first location in the
 *  string s1 where any character from the string s2 occurs, or -1 if s1
 *  contains no characters from s2.
 *
 *  By Jake Milder
 */

#include <stdio.h>

int any(char s1[], char s2[]);
void run(char s1[], char s2[]);

int main(void) {

    char name[] = "Jake Milder";

    run(name, "aeiou");
    printf("\n\n");
    run(name, "i");
    printf("\n\n");
    run(name, "u");
    printf("\n\n");


    return 0;
}

void run(char s1[], char s2[]) {
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    int firstIndex = any(s1, s2);
    printf("First character at %d\n", firstIndex);
}

int any(char s1[], char s2[]) {
    int i, j, k, found;
    i = j = k = 0;
    found = -1;

    while(s1[i] != '\0') {

        for(j=0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j]) {
                break;
            }
        }

        if(s2[j] != '\0') {
            found = i;
            break;
        }
        i++;
    }

    return found;
}
