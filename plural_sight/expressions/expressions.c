#include <stdio.h>

// define a boolean datatype if not using c++
#ifndef __cplusplus
typedef char bool;
#define true 1
#define false 0
#endif

int main(int argc, char** argv) {

    bool c2f = false;
    double c = 0;
    double f = 86;

    if (c2f) {
        f = c * 9/5 + 32;
    } else {
        c = (f - 32) * 5/9;
    }

    printf("%f C = %f F\n", c, f);

    return 0;
}
