/*
 * Exercise 1-24 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 *  By Jake Milder
 *
 *  Report basic syntax errors given a c program
 *
 *  Implementing a queue with techniques the book has covered.
 */

#include <stdio.h>

#define QUEUE_BUFFER 1000

#define TRUE 1
#define FALSE 0

int readline(char line[]);
int processChar(char c, int lineNumber);

/* conditional helper functions */
int isClosingCharacter(char c);
int isOpeningCharacter(char c);
int isQuote(char c);
int isMatching(char a, char b);


/* queue */
char queue[QUEUE_BUFFER];
int qlength = 0;

// add character to end of queue
void enqueue(char c);
// remove last character from queue and return it
char  dequeue();
// return last character from queue
char peek();
// print queue
void printQueue();


/* queue helper methods */
int inQuote();
int inComment();
int inInlineComment();
int inMultilineComment();
int _inInlineComment = FALSE;
int _inMultilineComment = FALSE;

/*
 * Main method
 */
int main() {
    int c;
    int lineNumber = 1;
    int errors = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n')
            lineNumber++;

        errors += processChar(c, lineNumber);
    }
    
    while(qlength > 0) {
        printf("Found unclosed character '%c'\n", dequeue());
        errors++;
    }

    if(errors > 0) {
        printf("Found %d errors\n", errors);
    }
    return 0;
}

/* 
 * Process character and return error error code
 */
int processChar(char c, int lineNumber) {
    if(_inInlineComment || _inMultilineComment) {   // if in a comment
        if(_inInlineComment && c == '\n') {
            _inInlineComment = FALSE;
        } else if(_inMultilineComment) {
            if(qlength > 0) {
                char lastChar = peek();
                if(lastChar  == '*') {
                    if(c == '/') {  // '*/' detected end multiline comment
                        _inMultilineComment = FALSE;
                        dequeue();
                    } else {        // '*' detected but next character was not '/', remove '*'
                        dequeue();
                    }
                } else if(c == '*') { // last character was not '*' but current is, queue it.
                    enqueue(c);
                }
            } else if(c == '*') {
                enqueue(c);
            }
        }
    } else if(qlength > 0) {
        char lastChar = peek();
        if(c == '\n' && isQuote(lastChar)) { // if new line and last queued character was a quote then error
            printf("%d: quote not properly closed\n", lineNumber-1);
            dequeue();  // remove bad quote
            return 1;
        } else if(isQuote(lastChar)) {   // if within a quote
            if(lastChar == '\'' && c == '\'') {
                dequeue();
            } else if(lastChar == '"' && c == '"') {
                dequeue();
            }
        } else if(isOpeningCharacter(c)) {
            enqueue(c);
        } else if(isQuote(c)) {  // if not within quote and current character is a quote, enqueue it
            enqueue(c);
        } else if(isMatching(lastChar, c)) {
            dequeue();
        } else if(isClosingCharacter(c)) {   // if closing, then match not found, so error
            printf("%d: Unexpected close '%c'\n", lineNumber, c);
            return 1;
        } else if(lastChar == '/' && c == '*') {
            _inMultilineComment = TRUE;
            dequeue();  // dequeue backslash
        } else if(lastChar == '/' && c == '/') {
            _inInlineComment = TRUE;
            dequeue();  // dequeue backslash
        } else if(lastChar == '/') {   // last char is backslash and current char isn't '/' or '*'
            dequeue();  // Remove backslash as it is not starting a comment
        } else if(c == '/') { // capture start of a comment
            enqueue(c);
        }
    } else if(qlength == 0) {
        if(isClosingCharacter(c)) {
            printf("%d: Unexpected close '%c'\n", lineNumber, c);
            return 1;
        } else if(isOpeningCharacter(c) || isQuote(c) || c == '/') {
            enqueue(c);
        }

    }

    // if in a comment, dequeue the last two characters and set the boolean flag
    if(inComment()) {
        if(inInlineComment())
            _inInlineComment = TRUE;
        else
            _inMultilineComment = TRUE;

        dequeue();
        dequeue();
    }
    return 0;
}

/*******************
 * Queue Functions *
 *******************/

/*
 * Add character to end of queue
 */
void enqueue(char c) {
    queue[qlength] = c;
    qlength++;
}

/*
 * Remove last element from queue
 */
char dequeue() {
    if(qlength > 0) {
        --qlength;
        return queue[qlength];
    } else {
        return '\0';
    }
}

/* 
 * Return last element from queue
 */
char peek() {
    if(qlength > 0) {
        return queue[qlength - 1];
    } else {
        return '\0';
    }
}

/*
 * Print queue
 */
void printQueue() {
    for(int i = 0; i < qlength; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

/*
 * Return 1 (TRUE) if last character in queue is a single/double quote
 * else return 0 (FALSE)
 */
int inQuote() {
    if(qlength > 0) {
        char lastChar = peek();
        return lastChar == '\'' || lastChar == '"';
    }
    return FALSE;
}

/*
 * Return 1 (TRUE) if last two characters in queue start a comment
 * else return 0 (FALSE)
 */
int inComment() {
    if(qlength > 1) {
        return inInlineComment() || inMultilineComment();
    }
    return FALSE;
}

/*
 * Return 1 (TRUE) if last two characters in queue are '//'
 * else return 0 (FALSE)
 */
int inInlineComment() {
    if(qlength > 1) {
        char lastChar = peek();
        if (lastChar == '/') {
            lastChar = dequeue();   // dequeue so that we can check the next char
            char penultimateChar = peek();
            enqueue(lastChar);      // add last character back to queue
            return penultimateChar == '/';
        }
    }
    return FALSE;
}

/*
 * Return 1 (TRUE) if last two characters in queue are '/' and '*'
 * else return 0 (FALSE)
 */
int inMultilineComment() {
    if(qlength > 1) {
        char lastChar = peek();
        if (lastChar == '*') {
            lastChar = dequeue();   // dequeue so that we can check the next char
            char penultimateChar = peek();
            enqueue(lastChar);      // add last character back to queue
            return penultimateChar == '/';
        }
    }
    return FALSE;
}

/********************************
 * Conditional Helper Functions *
 ********************************/

/*
 * Return 1 (TRUE) if character is ) or } or ]
 * else return 0 (FALSE)
 */
int isClosingCharacter(char c) {
    return c == ')' || c == ']' || c == '}';
}

/*
 * Return 1 (TRUE) if character is ( or { or [
 * else return 0 (FALSE)
 */
int isOpeningCharacter(char c) {
    return c == '(' || c == '[' || c == '{';
}


/*
 * Return 1 (TRUE) if character is single or double quote
 * else return 0 (FALSE)
 */
int isQuote(char c) {
    return c == '\'' || c == '"';
}

/*
 * Return 1(TRUE) if character b closes character a
 * else return 0 (FALSE)
 */
int isMatching(char a, char b) {
    return (a == '{' && b == '}') 
        || (a == '[' && b == ']')
        || (a == '(' && b == ')');
}

