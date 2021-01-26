#include <stdio.h>

int main() {
    int count = 10000; 
    while(count-- > 0) {
        printf("\e[1;1H\e[2J");
        printf("== Clear Screen 2 ==\n");
    }



    return 0;
}
