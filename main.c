
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    Student *studentList = NULL; 
    int studentCount = 0;        
    int studentCapacity = INITIAL_CAPACITY;
    int choice;

    // Initial Setup (Member 1)
    char userName[100];
    printf("Welcome to the Student Management System!\n");
    printf("Please enter your name: ");
    if (fgets(userName, sizeof(userName), stdin) != NULL) {
        userName[strcspn(userName, "\n")] = 0; // Remove trailing newline
        printf("Hello, %s!\n\n", userName);
    }
    
    // Attempting to Load File (Member 5)
    loadFromFile(&studentList, &studentCount, &studentCapacity);

    do {
        printf("\n--- MENU ---\n1. Add | 2. Display | 3. Search | 4. Modify | 5. Remove\n6. Sort (Asc) | 7. Sort (Desc) | 8. Average | 9. Exit\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("[!] Invalid input. Clearing buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); // Consume the newline

        switch(choice) {
            case 1:
                addStudent(&studentList, &studentCount, &studentCapacity);
                break;
            case 2:
                displayRecords(studentList, studentCount);
                break;
            case 3:
                // Simplified search for debug
                int roll;
                printf("Enter Roll: ");
                scanf("%d", &roll);
                int idx = searchRecord(studentList, studentCount, roll);
                if (idx != -1) {
                     printf("\n[+] Student Found:\n");
                     printf("Roll Number: %d\nName: %s\nMarks: %.2f\n", 
                            studentList[idx].rollNumber, 
                            studentList[idx].name, 
                            studentList[idx].marks);
                } else {
                     printf("\n[!] Student not found.\n");
                }
                break;
            case 4:
                modifyRecord(studentList, studentCount);
                break;
            case 5:
                removeStudentRecord(studentList, &studentCount);
                break;
            case 6:
                sortByMarksAscending(studentList, studentCount);
                printf("[+] Records sorted in ascending order of marks.\n");
                displayRecords(studentList, studentCount);
                break;
            case 7:
                sortByMarksDescending(studentList, studentCount);
                printf("[+] Records sorted in descending order of marks.\n");
                displayRecords(studentList, studentCount);
                break;
            case 8:
                double avg = calculateAverage(studentList, studentCount);
                printf("[+] Class Average: %.2f\n", avg);
                break;
            case 9:
                saveToFile(studentList, studentCount);
                free(studentList);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 9);

    return 0;
}