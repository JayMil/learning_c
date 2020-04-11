#include <stdio.h>

typedef int Counter;

int main() {
    Counter i = 0;
    while (i < 10) {
        printf("Hello %d\n", i++);
    }

    return 0;
}
