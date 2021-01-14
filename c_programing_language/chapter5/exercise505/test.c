/*
 * Exercise 5-05 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write versions of the library functions strcpyn, strcatn and strcmpn,
 * which operate on at most the first n characters of their argument strings.
 * For example, strcpyn(s,t,n) copies at most n characters of t to s.
 *
 * Tests for strcpyn, strcatn and strcmpn
 *
 *  By Jake Milder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules.h"
#include "cunit.h"

#define BUF 100



void test_strcmp();
void test_strcmpn();
void test_strcpyn();
void test_strcatn();

int main(void) {
    startSuite(1, 0);
    test_strcmp();
    test_strcmpn();
    test_strcpyn();
    test_strcatn();
    endSuite();
}

void test_strcatn() {
    startTest("Test strcatn");
    char s[BUF], t[BUF], expected[BUF];

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "HelloWorld");
    strcatn(s, t, 5);
    assertEqualsS(expected, s, "Concat full strings");

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "HelloW");
    strcatn(s, t, 1);
    assertEqualsS(expected, s, "Concat part strings");

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "HelloWorld");
    strcatn(s, t, 10);
    assertEqualsS(expected, s, "N more than string length");

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "Hello");
    strcatn(s, t, 0);
    assertEqualsS(expected, s, "N is zero");

    strcpy(s, "");
    strcpy(t, "World");
    strcpy(expected, "World");
    strcatn(s, t, 5);
    assertEqualsS(expected, s, "Concat to empty string");

    strcpy(s, "Hello");
    strcpy(t, "");
    strcpy(expected, "Hello");
    strcatn(s, t, 5);
    assertEqualsS(expected, s, "Concat an empty string");

    endTest();
}

void test_strcpyn() {
    startTest("Test strcpyn");
    char s[BUF], t[BUF], expected[BUF];

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "World");
    strcpyn(s, t, 5);
    assertEqualsS(expected, s, "Strings is fully copyied");

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "Wello");
    strcpyn(s, t, 1);
    assertEqualsS(expected, s, "First Letter copied");

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "World");
    strcpyn(s, t, 10);
    assertEqualsS(expected, s, "N more than string lengths should copy whole string");

    strcpy(s, "Hello");
    strcpy(t, "Wor");
    strcpy(expected, "Wor");
    strcpyn(s, t, 10);
    assertEqualsS(expected, s, "N more than partial string should copy whole string");

    strcpy(s, "Hello");
    strcpy(t, "World");
    strcpy(expected, "Hello");
    strcpyn(s, t, 0);
    assertEqualsS(expected, s, "N of zero will not copy");

    endTest();
}


void test_strcmp() {
    startTest("Test strcmp");
    assertEqualsI(0,  str_cmp("hello", "hello"), "Full string compare");
    assertEqualsI(-1, str_cmp("hello", "world"), "Different strings lower");
    assertEqualsI(1,  str_cmp("world", "hello"), "Different strings higher");
    assertEqualsI(-1, str_cmp("a", "apple"),     "Different length strings");
    assertEqualsI(1,  str_cmp("apple", "a"),     "Different length srings rev");
    endTest();
}

void test_strcmpn() {
    startTest("Test strcmpn");
    assertEqualsI(0,  strcmpn("hello bob", "hello rob", 6),   "First n characters match");
    assertEqualsI(-1, strcmpn("hello bob", "hello rob", 7),   "First n characters no match");
    assertEqualsI(0,  strcmpn("hello bob", "hello bob", 100), "Strings match and n larger than strings");
    assertEqualsI(-1, strcmpn("hello", "world", 1),           "Single character no match");
    assertEqualsI(1,  strcmpn("hello bob", "h", 9),           "Different lenght no match");
    endTest();
}



