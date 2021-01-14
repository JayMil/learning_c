/* * Exercise 5-05 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write versions of the library functions strcpyn, strcatn and strcmpn,
 * which operate on at most the first n characters of their argument strings.
 * For example, strcpyn(s,t,n) copies at most n characters of t to s.
 *
 * Unit testing framework for testing my exercises.
 * Creating my own rather than using an existing framework to get more
 * practice with c.
 *
 *  By Jake Milder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cunit.h"

const char * CLEAR = "\e[00m";
const char * RED = "\e[1;31m";
const char * GREEN = "\e[1;32m";

char *_testName;
int _testNum = 1;
int _passCount = 0;
int _failCount = 0;
short int _verbose = 0;
short int _showheader = 0;

void startSuite(short int verbose, short int showheader) {
    _verbose = verbose;
    _showheader = showheader;
}

void endSuite() {

}


void assertEqualsI(int expected, int actual, const char *msg) {
    if(expected == actual) {
        print_pass();
    } else {
        print_ifailure(expected, actual);
    }

    print_msg(msg);
}

void assertEqualsS(const char *expected, const char *actual, const char *msg) {
    if(strcmp(actual, expected) == 0) {
        print_pass();
    } else {
        print_sfailure(expected, actual);
    }

    print_msg(msg);
}

void startTest(const char *testName) {
    _testName = (char*) malloc(strlen(testName) * sizeof(char));
    strcpy(_testName, testName);

    if(_showheader)
        printHeader();
    _testNum = 1;
    _passCount = 0;
    _failCount = 0;
}

void endTest() {
    printf("%s: ", _testName);
    int testCount = _passCount+_failCount;
    if(_passCount == testCount) {
        printf("%d FAILED - ", _failCount);
        printf("%s", GREEN);
        printf("%d PASSED", _passCount);
        printf("%s", CLEAR);
        printf(" out of %d\n", testCount);
    } else {
        printf("%s", RED);
        printf("%d FAILED", _failCount);
        printf("%s", CLEAR);
        printf(" - %d PASSED", _passCount);
        printf(" out of %d\n", testCount);
    }

    free(_testName);
    _testName = NULL;
}

void print_pass() {
    _passCount++;
    if(_verbose) {
        printf("%d: ", _testNum++);
        printf("%s", GREEN);
        printf("PASS: ");
        printf("%s", CLEAR);
    }
}


void print_sfailure(const char *expected, const char *actual) {
    _failCount++;
    if(_verbose) {
        printf("%d: ", _testNum++);
        printf("%s", RED);
        printf("FAIL: expected '%s' but recieved '%s': ", expected, actual);
        printf("%s", CLEAR);
    }
}

void print_ifailure(int expected, int actual) {
    _failCount++;
    if(_verbose) {
        printf("%d: ", _testNum++);
        printf("%s", RED);
        printf("FAIL: expected '%d' but recieved '%d': ", expected, actual);
        printf("%s", CLEAR);
    }
}

void print_msg(const char *msg) {
    if(_verbose)
        printf("%s%s\n", msg, CLEAR);
}

void printHeader() {
    char styleChar = '=';

    // two styleChars and a space before and after test name
    int wrapLength = 6;

    size_t lineLength = strlen(_testName) + wrapLength;
    char *styleLine = (char*) malloc(lineLength * sizeof(char));
    for(size_t i=0; i < lineLength; i++) {
        styleLine[i]=styleChar;
    }

    printf("%s\n", styleLine);
    printf("%c%c %s %c%c\n", styleChar, styleChar, _testName, styleChar, styleChar);
    printf("%s\n", styleLine);

    free(styleLine);
}
