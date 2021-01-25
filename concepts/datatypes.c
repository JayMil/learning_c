#include<stdio.h>

int minint();
unsigned int minuint();

long minlong();
unsigned long minulong();

int main() {
    char a = 0;
    char c = 4;
    unsigned char b = 0;

    printf("int: %d\n", --a);
    printf("unsigned int: %u\n", --b);

    int min = minint(1000);
    printf("min int: %d\n", min);

    unsigned int umin = minuint();
    printf("min uint: %u\n", umin);

    
    long lmin = minlong(min*1);
    printf("min long: %ld\n", lmin);

    unsigned long ulmin = minulong();
    printf("min ulong: %lu\n", ulmin);


    return 0;
}

/* minint: calculate min integer */
int minint(int down) {
    int i = 0;
    int prev = i;
    
    while(i <= 0) {
        i -= down;
        prev = i;
    }

    i = prev;

    while(--i <= 0) {
        prev = i;
    }


    return prev;
}

/* minuint: calculate min integer */
unsigned int minuint() {
    unsigned int i = 0;
    unsigned int prev = i;
    while(--i < 0)
        prev = i;

    return prev;
}

/* minlong: calculate min long */
long minlong(int down) {
    long i = 0;
    long prev = i;
    
    while(i <= 0) {
        i -= down;
        prev = i;
    }

    i = prev;

    while(--i <= 0) {
        prev = i;
    }

    return prev;
}

/* minulong: calculate min long */
unsigned long minulong() {
    unsigned long i = 0;
    unsigned long prev = i;
    while(--i < 0)
        prev = i;

    return prev;
}
