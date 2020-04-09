#include <stdio.h>

void apples_set(int value);
int apples_get();

// must be static or will collide with apples global data variable
static int data;
void oranges_set(int value) {
    data = value;
}
int oranges_get() {
    return data;
}

int main() {
    // intitial value of a global unintialized int is zero.
    printf("apples:%d\n", apples_get());
    printf("oranges:%d\n", oranges_get());

    apples_set(5);
    oranges_set(10);

    // oranges and apples have the same value as the global data variable is getting overwritten
    printf("apples:%d\n", apples_get());
    printf("oranges:%d\n", oranges_get());

    return 0;
}
