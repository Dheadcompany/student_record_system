#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================
// Data Architect & Core Structure (Adeola - Member 1)
// ============================================================
typedef struct {
    char name[100];
    int rollNumber;
    float marks; // Set to float to handle decimal grading
} Student;

// --- Function Prototypes ---
// Member 3 (Nelson)
void addStudent(Student **records, int *count, int *capacity);
void modifyStudent(Student *records, int count);
void checkPassFail(float marks);

// Future Members (Placeholders)
void searchRecord(Student *records, int count);
void saveToFile(Student *records, int count);

int main() {
    char userName[100];
    int count = 0;
    int capacity = 5;

    // --- Memory Management: Initial allocation (Adeola) ---
    Student *records = (Student *)malloc(capacity * sizeof(Student));
    if (!records) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // --- Initial Greeting (Adeola) ---
    printf("--- Welcome to the Student Record System ---\n");
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = 0; // Strip trailing newline
    printf("Hello, %s!\n\n", userName);

    // ============================================================
    // Flow Control & Menu System (Kelechi - Member 2)
    // ============================================================
    int choice;
    do {
        printf("\nSelect from the menu options:\n");
        printf("1. Add Student\n");
        printf("2. Modify Student\n");
        printf("3. Search Student\n");
        printf("4. Save Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1: 
                printf("\n[INFO] Add Student function called.\n");
                addStudent(&records, &count, &capacity);
                break;
            case 2: 
                printf("\n[INFO] Modify Student function called.\n");
                modifyStudent(records, count);
                break;
            case 3: 
                printf("\n[INFO] Search Student function called (Pending Member 4).\n");
                // searchRecord(records, count);
                break;
            case 4: 
                printf("\n[INFO] Save Records function called (Pending Member 5).\n");
                // saveToFile(records, count);
                break;
            case 5: 
                printf("\nExiting system...\n");
                break;
            default: 
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 5);

    // --- Memory Management Final cleanup (Adeola) ---
    free(records);
    printf("System closed. Memory freed.\n");
    return 0;
}

// ============================================================
// Record Management Specialist (Nelson - Member 3)
// ============================================================

void checkPassFail(float marks) {
    if (marks > 40.0) { 
        printf("Status: PASSED\n");
    } else {
        printf("Status: FAILED\n");
    }
}

void addStudent(Student **records, int *count, int *capacity) {
    // If the array is full, use realloc to double its size dynamically
    if (*count >= *capacity) {
        *capacity *= 2;
        *records = (Student *)realloc(*records, *capacity * sizeof(Student));
        if (*records == NULL) {
            printf("Memory allocation failed during reallocation!\n");
            exit(1);
        }
    }

    printf("\n--- Add New Student ---\n");
    printf("Enter Student Name: ");
    scanf(" %99[^\n]", (*records)[*count].name); // Reads strings with spaces safely
    
    printf("Enter Roll Number: ");
    scanf("%d", &(*records)[*count].rollNumber);
    
    printf("Enter Marks (0-100): ");
    scanf("%f", &(*records)[*count].marks);

    // Call the pass/fail threshold check
    checkPassFail((*records)[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

void modifyStudent(Student *records, int count) {
    int roll;
    int found = 0;
    
    printf("\n--- Modify Student Record ---\n");
    if (count == 0) {
        printf("No records available to modify.\n");
        return;
    }

    printf("Enter Roll Number of student to modify: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (records[i].rollNumber == roll) {
            found = 1;
            printf("Current Name: %s | Current Marks: %.2f\n", records[i].name, records[i].marks);
            
            printf("Enter new name: ");
            scanf(" %99[^\n]", records[i].name);
            
            printf("Enter new marks: ");
            scanf("%f", &records[i].marks);
            
            checkPassFail(records[i].marks);
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Error: Student with Roll Number %d not found.\n", roll);
    }
}