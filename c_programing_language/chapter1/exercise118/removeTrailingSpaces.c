/*
 * remove trailing spaces from line
 * Note line must be less than 1000 chars
 */

#include <stdio.h>

#define LINE_MAX_LENGTH 1000

int readline(char s[]);
int removeTrailingSpaces(char s[]);

int main() {
    int lineLength;
    char line[LINE_MAX_LENGTH];

    while((lineLength = readline(line)) > 0) {
        lineLength = removeTrailingSpaces(line);
        if(lineLength > 0) {
            printf("%d: '%s'\n", lineLength, line);
        }
    }

    return 0;
}

int readline(char s[]) {
    int i, c;

    for(i = 0; i < LINE_MAX_LENGTH && ((c = getchar()) != EOF) && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}

int removeTrailingSpaces(char s[]) {
    int i, lastNonBlankIndex;
    lastNonBlankIndex = -1;
    // set string length
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] != '\t' && s[i] != ' ' && s[i] != '\n') {
            lastNonBlankIndex = i;
        }
    }

    s[lastNonBlankIndex + 1] = '\0';
    return lastNonBlankIndex;
}
