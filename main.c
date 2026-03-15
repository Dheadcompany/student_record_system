#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

// Structure for student
typedef struct {
    char name[MAX_NAME];
    int rollNumber;
    float marks;
} Student;

// Function Prototypes
void addStudent(Student **list, int *count);
void searchStudent(Student *list, int count);
void saveRecords(Student *list, int count);
void exitProgram(Student *list);

// Main function
int main() {
    Student *studentList = NULL; 
    int studentCount = 0;        
    int choice;

    printf("Welcome to Student Management System!\n");

    // Main Menu Loop
    do {
        printf("\n Select option from the menu \n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Save Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(&studentList, &studentCount);
                break;
            case 2:
                searchStudent(studentList, studentCount);
                break;
            case 3:
                saveRecords(studentList, studentCount);
                break;
            case 4:
                exitProgram(studentList);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}

// Function to add a student
void addStudent(Student **list, int *count) {
    (*count)++;
    *list = realloc(*list, sizeof(Student) * (*count));
    if(*list == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("\nEnter student name: ");
    scanf(" %[^\n]s", (*list)[*count - 1].name);

    printf("Enter roll number: ");
    scanf("%d", &(*list)[*count - 1].rollNumber);

    printf("Enter marks: ");
    scanf("%f", &(*list)[*count - 1].marks);

    if((*list)[*count - 1].marks >= 40)
        printf("Status: Pass\n");
    else
        printf("Status: Fail\n");

    printf("Student added successfully!\n");
}

// Function to search a student by roll number
void searchStudent(Student *list, int count) {
    if(count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    int roll;
    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(list[i].rollNumber == roll) {
            printf("Student Found:\n");
            printf("Name: %s\n", list[i].name);
            printf("Roll Number: %d\n", list[i].rollNumber);
            printf("Marks: %.2f\n", list[i].marks);
            printf("Status: %s\n", list[i].marks >= 40 ? "Pass" : "Fail");
            return;
        }
    }

    printf("Student with roll number %d not found.\n", roll);
}

// Function to save records to file
void saveRecords(Student *list, int count) {
    if(count == 0) {
        printf("\nNo student records to save.\n");
        return;
    }

    FILE *file = fopen("students.txt", "w");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%.2f\n", list[i].name, list[i].rollNumber, list[i].marks);
    }

    fclose(file);
    printf("Records saved to students.txt successfully.\n");
}

// Function to exit program
void exitProgram(Student *list) {
    free(list);
    printf("\nAll memory freed. Exiting program. Goodbye!\n");
}
