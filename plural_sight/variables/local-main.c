#include <stdio.h>

void uninitializedInt();
void initializedInt();

int main() {
    uninitializedInt();
    initializedInt();

    return 0;
}

void uninitializedInt() {
    printf("\n\n=== Uninitialized Int ===\n\n");
    int apples;
    int oranges;


    // these variables don't have an initial value, so there data will differ between exections
    printf("appples=%d oranges=%d\n", apples, oranges);

}

void initializedInt() {
    printf("\n\n=== Initialized Int ===\n\n");
    int apples = 5;
    int oranges = apples;

    apples = 4;

    printf("appples=%d oranges=%d\n", apples, oranges);

}
