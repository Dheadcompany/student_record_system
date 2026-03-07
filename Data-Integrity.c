#include "student.h"

// Task 1: Sorting Logic (Ascending)
void sortByMarksAscending(Student *records, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (records[j].marks > records[j + 1].marks) {
                Student temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

// Task 1: Sorting Logic (Descending)
void sortByMarksDescending(Student *records, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (records[j].marks < records[j + 1].marks) {
                Student temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

// Task 2: Record Removal
void removeStudentRecord(Student *records, int *count) {
    if (*count == 0) {
        printf("\n[!] No records to remove.\n");
        return;
    }

    int roll;
    printf("Enter Roll Number to remove: ");
    scanf("%d", &roll);
    getchar(); // consume newline

    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (records[i].rollNumber == roll) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\n[!] Student with Roll Number %d not found.\n", roll);
        return;
    }

    // Shift remaining elements
    for (int i = index; i < *count - 1; i++) {
        records[i] = records[i + 1];
    }
    (*count)--;
    printf("\n[+] Student record removed successfully.\n");
}

// Task 3: Input Validation - Check Roll Number Uniqueness
int isRollNumberUnique(Student *records, int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (records[i].rollNumber == rollNumber) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

// Task 3: Input Validation - Validate Marks (0-100)
int isValidMarks(double marks) {
    return marks >= 0.0 && marks <= 100.0;
}
