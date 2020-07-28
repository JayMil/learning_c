/*
 * Exercise 2-04 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  Create a function squeeze(s1, s2) that deletes each character in s1
 *  that matches any character in s2
 *
 *  By Jake Milder
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) {

    char name[] = "Jake Milder";
    char vowels[] = "aeiou";

    printf("s1: %s\n", vowels);
    printf("s2: %s\n", name);
    printf("squeeze..\n");
    squeeze(name, vowels);
    printf("%s\n", name);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    i = j = k = 0;

    while(s1[i] != '\0') {

        for(j=0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j]) {
                break;
            }
        }

        if(s2[j] == '\0') {
            s1[k++] = s1[i];
        }
        i++;
    }

    s1[k] = '\0';
}
