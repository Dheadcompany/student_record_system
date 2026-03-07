#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include "student.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char userName[100];
    Student *students = NULL;
    int count = 0;
    int capacity = INITIAL_CAPACITY;

    // Greeting (Member 1)
    printf("--- Welcome to the Student Record System --- ");
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = 0;
    printf("\nHello, %s!\n", userName);

    // Initial allocation
    students = (Student *)malloc(capacity * sizeof(Student));
    if (students == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Load from file (Member 5)
    loadFromFile(&students, &count, &capacity);

    int choice;
    do {
        printf("\n======= STUDENT RECORD SYSTEM =======\n");
        printf("1. Add Student (Member 3)\n");
        printf("2. Display All Records (Member 4)\n");
        printf("3. Search by Roll Number (Member 4)\n");
        printf("4. Modify Record (Member 3)\n");
        printf("5. Remove Record (Member 6)\n");
        printf("6. Sort by Marks Ascending (Member 6)\n");
        printf("7. Sort by Marks Descending (Member 6)\n");
        printf("8. Calculate Average Marks (Member 4)\n");
        printf("9. Save and Exit (Member 5)\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("[!] Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addStudent(&students, &count, &capacity);
                break;
            case 2:
                displayRecords(students, count);
                break;
            case 3: {
                int roll;
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);
                getchar();
                int idx = searchRecord(students, count, roll);
                if (idx != -1) {
                    printf("\n--- Student Found ---\n");
                    printf("Roll No: %d\nName: %s\nMarks: %.2f\nResult: %s\n",
                           students[idx].rollNumber, students[idx].name, 
                           students[idx].marks, (students[idx].marks >= 40) ? "Pass" : "Fail");
                } else {
                    printf("\n[!] Student not found.\n");
                }
                break;
            }
            case 4:
                modifyRecord(students, count);
                break;
            case 5:
                removeStudentRecord(students, &count);
                break;
            case 6:
                sortByMarksAscending(students, count);
                printf("\n[+] Records sorted by marks (Ascending).\n");
                displayRecords(students, count);
                break;
            case 7:
                sortByMarksDescending(students, count);
                printf("\n[+] Records sorted by marks (Descending).\n");
                displayRecords(students, count);
                break;
            case 8: {
                double avg = calculateAverage(students, count);
                printf("\n[i] Average Marks for the class: %.2f\n", avg);
                break;
            }
            case 9:
                saveToFile(students, count);
                printf("Saving and exiting...\n");
                break;
            default:
                printf("[!] Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    // Free memory (Member 1)
    free(students);
    printf("Memory freed. Goodbye!\n");

    return 0;
}
=======
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
>>>>>>> ee16e582222c743746bc47a3314eb35b20d5df8e
