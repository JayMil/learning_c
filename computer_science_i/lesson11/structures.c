#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"

void createArrayOfContigousStudends(int n);
void createArrayOfPointersToStudents(int n);
void createArrayOfPointersToContigousStudents(int n);

int main() {

    Student *s = createStudent(12345678, "Katherine", "Johnson", 4.0, 1918, 9, 26);

    printStudent(s);

    char *ss = studentToString(s);
    printf("%s\n", ss);


    createArrayOfContigousStudends(3);

    createArrayOfPointersToStudents(3);

    createArrayOfPointersToContigousStudents(3);

    return 0;
}

// Array of contiguous structures
void createArrayOfContigousStudends(int n) {
    Student *roster = (Student *) malloc(sizeof(Student) * n);
}

// Array of pointers to dynamic structures
void createArrayOfPointersToStudents(int n) {
    Student **roster = (Student **) malloc(sizeof(Student*) * n);
    for (int i=0; i<n; i++) {
        roster[i] = (Student *) malloc(sizeof(Student));
    }
}

// Array of pointers to contigous structures
void createArrayOfPointersToContigousStudents(int n) {
    Student **rosterPointers = (Student **) malloc(sizeof(Student*) * n);
    Student *rosterData = (Student *) malloc(sizeof(Student) * n);
    for (int i=0; i<n; i++) {
        rosterPointers[i] = &rosterData[i];
    }
}


