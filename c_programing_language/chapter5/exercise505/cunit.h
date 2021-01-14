/*
 * Exercise 5-05 from
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


/*
 * Check if two integers are equal.
 * Print PASS: *msg if they are
 * print FAIL(actual, expected): *msg if they are not
 */
void assertEqualsI(int expected, int actual, const char *msg);

/*
 * Check if two strings are equal.
 * Print PASS: *msg if they are
 * print FAIL(actual, expected): *msg if they are not
 */
void assertEqualsS(const char *expected, const char *actual, const char *msg);

/*
 * Signify the start of a suite or series of tests.
 */
void startSuite(short int verbose, short int showheader);

/*
 * Signify the end of a suite or series of tests.
 */
void endSuite();

/*
 * Signify the start of a test.
 */
void startTest(const char *testName);

/* 
 * Signify the end of a test.
 */
void endTest();

void printHeader();
void print_pass();
void print_msg(const char *msg);
void print_ifailure(int expected, int actual);
void print_sfailure(const char *expected, const char *actual);

