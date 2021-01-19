#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"

Student * createStudent(int nuid, char *firstName, char *lastName, double gpa,
                        int year, int month, int day) {

    Student *s = (Student *) malloc(sizeof(Student) * 1);
    s->nuid = nuid;
    s->firstName = (char *) malloc(sizeof(char) * (strlen(firstName) + 1));
    strcpy(s->firstName, firstName);
    s->lastName = (char *) malloc(sizeof(char) * (strlen(lastName) + 1));
    strcpy(s->lastName, lastName);
    s->gpa = gpa;
    s->dateOfBirth.year = year;
    s->dateOfBirth.month = month;
    s->dateOfBirth.day = day;

    return s;
}

void printStudent(const Student *s) {
    char *str = studentToString(s);
    printf("%s\n", str);
    free(str);
    return;
}


/**
 * This function returns a string representation of 
 * the given student structure
 */
char * studentToString(const Student *s) {
    char buffer[1000];
    sprintf(buffer, "%s, %s (%08d), %.2f", s->lastName, s->firstName, s->nuid, s->gpa);
    char *result = (char *) malloc( (strlen(buffer) + 1) * sizeof(char));
    strcpy(result, buffer);
    return result;
}
