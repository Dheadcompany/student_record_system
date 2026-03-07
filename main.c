#include <stdio.h>
#include <stdlib.h>
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
