#include <stdio.h>

char* template ="\
As int              %d \n\
As hex int          %x \n\
As double           %f \n\
As sci not double   %e \n\
As char             %c \n\
As string           %s \n\
As pointer          %p \n\
";

int main() {
    int value = 5;
    printf("Int 5\n");
    printf(template, value);
    printf("\n");

    double dvalue = 5.0;
    printf("double 5.0\n");
    printf(template, dvalue);


    return 0;
}
