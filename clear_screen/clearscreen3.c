#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 0;
    int count = 10000;
    clock_t t1, t2;

    t1 = clock();
    while(i++<count) {
        system("clear");
        printf("== Clear Screen 1 ==\n");
    }

    t1 = clock() - t1;

    i = 0;
    t2 = clock();
    while(i++<count) {
        printf("\e[1;1H\e[2J");
        printf("== Clear Screen 2 ==\n");
    }

    t2 = clock() - t2;

    printf("Time taken by system\(\"clear\") %f\n", ((double)t1) / CLOCKS_PER_SEC);
    printf("Time taken by regex %f\n", ((double)t2) / CLOCKS_PER_SEC);


    return 0;
}

