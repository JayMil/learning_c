#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    int pos = (a > 0) + (b > 0) + (c > 0);

    printf("POS: %d", pos);

    return 0;
}
