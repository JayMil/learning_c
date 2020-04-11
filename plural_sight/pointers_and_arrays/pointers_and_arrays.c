#include <stdio.h>

void print_array(int * p, int length);
void bad_print_array(int * p, int length);

int main(int argc, char** argv) {
    // prints the three values
    int a[3] = { 1, 2, 3};
    printf("{1, 2, 3}\n");
    bad_print_array(a, 3);

    // prints a "random" three values
    int b[3];
    printf("{}\n");
    bad_print_array(b, 3);

    // prints 0's
    int c[3] = {0};
    printf("{0}\n");
    bad_print_array(c, 3);

    return 0;
}

// print the contents of an int array
void print_array(int * p, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", *(p + i));
    }
}

// this function will print the contents of an array, plus one more
//  The last value printed will be invalid as it is not considered in the
//  array and is in the next adjacent memory location.
void bad_print_array(int * p, int length) {
    for (int i = 0; i <= length; i++) {
        printf("%d\n", *(p + i));
    }
}

