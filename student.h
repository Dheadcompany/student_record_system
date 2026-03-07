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

// Function prototypes for file operations (Member 5)
void saveToFile(Student *students, int count);
void loadFromFile(Student **students, int *count, int *capacity);

// Function prototypes for search and analytics (Member 4)
void displayRecords(Student *records, int count);
int searchRecord(Student *records, int count, int targetRoll);
double calculateAverage(Student *records, int count);

// Function prototypes for record management (Member 3)
void addStudent(Student **records, int *count, int *capacity);
void modifyRecord(Student *records, int count);

// Function prototypes for sorting and integrity (Member 6)
void sortByMarksAscending(Student *records, int count);
void sortByMarksDescending(Student *records, int count);
void removeStudentRecord(Student *records, int *count);
int isRollNumberUnique(Student *records, int count, int rollNumber);
int isValidMarks(double marks);

#endif // STUDENT_H