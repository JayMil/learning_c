#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/* Read a file character by character */
void readFileByCharacters();

/* Read a file by line */
void readFileByLine();

int main(int argc, char **argv) {
    //readFileByCharacters();
    readFileByLine();

    return 0;
}

void readFileByLine() {
    printf("== Read File By Line ==\n");
    FILE *f = fopen("./data/students.csv", "r");
    char s[100];
    char *line = fgets(s, 100, f);
    while(line != NULL) {
        // Remove end line character
        int n = strlen(s);
        if(s[n-1] == '\n') {
            s[n-1] = '\0';
        }

        printf("line = %s\n", line);
        line = fgets(s, 100, f);
    }
    fclose(f);

}

void readFileByCharacters() {
    printf("== Read File By Characters ==\n");
    FILE *f = fopen("./data/students.csv", "r");
    char c = fgetc(f);
    while(c != EOF) {
        //printf("c = %c\n", c);
        printf("%c", c);
        c = fgetc(f);
    }

    fclose(f);

}
