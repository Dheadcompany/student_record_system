#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"
#define INITIAL_CAPACITY 10
#define MAX_NAME_LENGTH 100

typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    double marks;
} Student;

// Function prototypes for file operations
void saveToFile(Student *students, int count);
void loadFromFile(Student **students, int *count, int *capacity);

typedef struct {
char name[100];
int rollNumber;
float marks;
} Student;

#endif //STUDENT_H
