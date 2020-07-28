#include <stdio.h>
#include <string.h>

int atoi(char s[]);

int main(void) {
    int a = atoi("1234567890");
    printf("%d\n", a);
    printf("%d\n", "1234567890");
    return 0;
}

int atoi(char s[]) {
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
