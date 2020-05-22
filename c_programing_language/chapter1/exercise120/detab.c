/*
 * Exercise 1-20 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Replace tabs with four spaces
 *
 */

#include <stdio.h>

#define LINE_MAX_LENGTH 1000

int readline(char line[]);
int len(char arr[]);

void detab(char line[]);
void mergeCharArrays(char array1[], char array2[], int startIndex);

int main() {
    char line[LINE_MAX_LENGTH];
    int lineLength = 0;


    while((lineLength = readline(line)) != EOF) {
        detab(line);
        int lineLen  = len(line);
        printf("%2d: '%s'\n", lineLen, line);
    }
    return 0;
}

void detab(char line[]) {
    for(int i=0; line[i] != '\0'; i++) {
        if(line[i] == '\t') {
            line[i] = ' ';
            char spaces[] = "   ";
            mergeCharArrays(line, spaces, i);
            i += 3;
        }
    }
}

int readline(char line[]) {
    int c, lineLength;

    for(lineLength = 0; lineLength < (LINE_MAX_LENGTH-1) && (c = getchar()) != EOF && c != '\n'; lineLength++) {
        line[lineLength] = c;
    }

    line[lineLength] = '\0';

    if(lineLength == 0 && c == EOF)
        return EOF;
    else
        return lineLength;
}

void mergeCharArrays(char array1[], char array2[], int startIndex) {
    int array1Length = len(array1);
    int array2Length = len(array2);
    
    for(int j = startIndex; j < (array1Length + array2Length); j += array2Length) {
        for(int i = 0; i < array2Length; i++) {
            int tempChar = array1[j + i];
            array1[j + i] = array2[i];
            array2[i] = tempChar;
        }
    }

    array1[array1Length + array2Length] = '\0';
}

int len(char arr[]) {
    int len;
    for(len = 0; arr[len] != '\0'; len++)
        ;
    return len;
}

