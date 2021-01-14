/*
 * Exercise 5-05 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write versions of the library functions strcpyn, strcatn and strcmpn,
 * which operate on at most the first n characters of their argument strings.
 * For example, strcpyn(s,t,n) copies at most n characters of t to s.
 *
 * Header file for strcpyn, strcatn and strcmpn
 *
 *  By Jake Milder
 */


/*
 * Copy the first n characters from t to s.
 */
void strcpyn(char *s, const char *t, int n);


/*
 * Concatenate the first n characters of t to s.
 */
void strcatn(char *s, const char *t, int n);


/*
 * Compare the first n characters of t to s.
 * Return <0 if s<t, 0 if s==t, >0 if s>t
 */
int strcmpn(const char *s, const char *t, int n);

/*
 * Compare s to t
 * Return -1 if s<t 
 *         0 if s==t, 
 *         1 if s>t
 */
int str_cmp(const char *s, const char *t);

