#include <stdio.h>

int main() {
    unsigned char a = 170;
    unsigned char b = 90;
    unsigned char c = 3;
    unsigned char d = 4;
    printf("170               1010 1010\n");
    printf("90                0101 1010\n");
    printf("170 & 90 = %d     0000 1010\n", (a & b));
    printf("170 | 90 = %d    1111 1010\n", (a | b));
    printf("170 ^ 90 = %d    1111 0000\n", (a ^ b));
    printf("170 >> 3 = %d     0001 0101\n", (a >> c));
    printf("170 << 4 = %d    1010 0000\n", (unsigned char)(a << d));
    return 0;
}
