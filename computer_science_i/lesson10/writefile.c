#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char **argv) {

    printf("== Write File ==\n");

    int a = 43;

    FILE *f = fopen("./data/data.txt", "w");


    char msg[100];
    sprintf(msg, "Hello World\n");

    fputs(msg, f);
    //fprintf(f, "Hello World!\n");

    fclose(f);

    return 0;
}

