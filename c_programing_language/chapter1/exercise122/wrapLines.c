/*
 * Exercise 1-22 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 * Fold long lines into multiple short lines
 *
 */

#include <stdio.h>

#define LINE_WIDTH 80
#define WORD_BUFFER 1000

void writeWord(char word[], int wordLength);

int main() {
    int lineLength = 0;
    int wordLength = 0;
    char word[WORD_BUFFER];
    char c;

    while((c = getchar()) != EOF) {
        if(c == '\n' || c == ' ') {
            // does the line length or line length plus current word exceed the width
            if((lineLength + wordLength) > (LINE_WIDTH-1)) {
                putchar('\n');
                lineLength = 0;
            }

            // is there a word to print
            if(wordLength > 0) {
                writeWord(word, wordLength);
                lineLength += wordLength;
                wordLength = 0;
            }

            putchar(c);
            if(c == ' ')
                lineLength++;
            else
                lineLength = 0;

        } else if(wordLength < WORD_BUFFER-1) {
            word[wordLength++] = c;
        }
    }
    return 0;
}

void writeWord(char word[], int wordLength) {
    for(int i=0; i < wordLength; i++) {
        putchar(word[i]);
    }
}
