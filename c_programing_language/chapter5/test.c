#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printName();
void setName(char *name);
char *_name;

int main() {
    printf("Hello World\n");
    setName("Pickle");
    printName();
    

    return 0;
}

void setName(char *name) {
    _name = (char*) malloc(strlen(name) * sizeof(char));
    //_name = name;
    strcpy(_name, name);
}

void printName() {
    printf("Hi %s\n", _name);
    free(_name);
}



