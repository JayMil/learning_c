#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int log(const char *msg);

int main(int argc, char **argv) {

    printf("== Write File ==\n");

    log("Hello World");
    log("Other log line that is a little longer");


    return 0;
}

int log(const char *msg) {
    FILE *f = fopen("./data/data.log", "a");

    //int pbuff=100;
    //char *logmsg = (char*) malloc(sizeof(char) * (strlen(msg)+1+pbuff));
    //sprintf(msg, "Hello World\n");

    //fputs(msg, f);
    fprintf(f, "INFO: ");
    fprintf(f, msg);
    fprintf(f, "\n");

    fclose(f);

}


