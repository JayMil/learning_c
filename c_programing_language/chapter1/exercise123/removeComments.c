/*
 * Exercise 1-23 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 *  Given c file, remove all comments
 *
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int cc, pc, inQuotes, inInlineComment, inMultilineComment;

    inQuotes = FALSE;
    inInlineComment = FALSE;
    inMultilineComment = FALSE;



    cc = getchar();
    pc = '\0';
    while(cc != EOF) {
        if(inInlineComment) {
            if(cc == '\n') {
                inInlineComment = FALSE;
            }
        } else if(inMultilineComment) {
            if(pc == '*' && cc == '/') {
                inMultilineComment = FALSE;
                // clear cc so that it doesn't get printed on next iteration
                cc = '\0';
            }
        } else if(inQuotes) {
            putchar(pc);
            if(cc == '"') {
                inQuotes = FALSE;
            }
        } else if(pc == '/' && cc == '/') {     // check for lineComment
            inInlineComment = TRUE;
        } else if(pc == '/' && cc == '*') {     // check for multilineComment
            inMultilineComment = TRUE;
        } else {
            putchar(pc);
            if(cc == '"') {
                inQuotes = TRUE;
            }
        }

        pc = cc;
        cc = getchar();
    }

    if(!inInlineComment && !inMultilineComment) {
        putchar(pc);
    }

    return 0;
}
