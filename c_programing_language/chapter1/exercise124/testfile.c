#include <stdio.h>

int main() {
    printf("Hello World\n");

    // error 1: extra parenthesis
    printf("Hello World\n"));

    // error 2: extra single quote
    char letterA = 'A'';

    // error 3: missing single quote
    car letterB = 'B;

    // error 4: extra double quote
    char word[] = "Hello"";

    // error 5: missing double quote
    char word[] = World";

    // error 6: missing opening square bracket
    char word] = "Hello";

    // error 7: missing closing square bracket
    char word[ = "World";

    // no errors ([{"'
    
    /* no errors 2
     * ( ' 
     * " [ {
     */

    return 0;
}

// error 8: extra currly brace
}
