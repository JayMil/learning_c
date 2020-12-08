/*
 * Exercise 3-02 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 *
 *  By Jake Milder
 */

#include <stdio.h>

#define BUFFER 1000
#define TRUE 1
#define FALSE 0

int escape(char s[], char t[]);

int unescape(char s[], char t[]);

int main(void) {
    printf("== Exercise 3-01 ==\n");
    char textToEscape[6][BUFFER] = {
        "one tab:	",
        "two tabs:		",
        "three tabs:			",
        "one newline:\n",
		"two newlines:\n\n",
		"three newlines:\n\n\n"
    };
    char textToUnescape[6][BUFFER] = {
        "one tab:\\t",
        "two tabs:\\t\\t",
        "three tabs:\\t\\t\\t",
        "one newline:\\n",
		"two newlines:\\n\\n",
		"three newlines:\\n\\n\\n"
    };
	char out[BUFFER];

    for(int i = 0; i < 6; i++) {
		escape(textToEscape[i], out);
        printf("Escaped '%s'\n", out);
		unescape(textToUnescape[i], out);
        printf("Unescaped '%s'\n", out);
    }

    return 0;
}

int escape(char s[], char t[]) {
	int cs, ct;
	cs = ct = 0;

	while(s[cs] != '\0' && cs < BUFFER) {
        switch(s[cs]) {
            case '\n':
                t[ct++] = '\\';
                t[ct++] = 'n';
                break;
            case '\t':
                t[ct++] = '\\';
                t[ct++] = 't';
                break;
            default:
                t[ct++] = s[cs];
                break;
        }
		cs++;
	}

	t[ct] = '\0';
	return ct;
}

int unescape(char s[], char t[]) {
	int cs, ct, escapeChar;
	cs = ct = 0;
    escapeChar = FALSE;

	while(s[cs] != '\0' && cs < BUFFER) {
        if (!escapeChar) {
            if (s[cs] == '\\') {
                escapeChar = TRUE;
            } else {
                t[ct++] = s[cs];
            }
        } else {
            switch(s[cs]) {
                case 'n':
                    t[ct++] = '\n';
                    break;
                case 't':
                    t[ct++] = '\t';
                    break;
                default:
                    t[ct++] = '\\';
                    t[ct++] = s[cs];
                    break;
            }
            escapeChar = FALSE;
        }
		cs++;
	}

	t[ct] = '\0';
	return ct;
}
