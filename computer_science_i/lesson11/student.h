typedef struct {
    int year;
    int month;
    int day;
} Date;


typedef struct {
    int nuid;
    char *firstName;
    char *lastName;
    double gpa;
    Date dateOfBirth;
} Student;

/**
 * This function creates a new instance with
 * the given values
 *
 */
Student * createStudent(int nuid, char *firstName, char *lastName, double gpa,
                        int year, int month, int day);

/**
 * This funciton prints a student structure's state
 * out to the standard output
 */
void printStudent(const Student *s);

/**
 * This function returns a string representation of 
 * the given student structure
 */
char * studentToString(const Student *s);

