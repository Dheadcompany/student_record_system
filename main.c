#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Structure Definition ---
typedef struct {
    char name[100];
    int rollNumber;
    int marks;
} Student;

// --- Function Prototypes ---
void addStudent(Student **records, int *count, int *capacity);
void searchRecord(Student *records, int count);
void saveToFile(Student *records, int count);

int main() {
    char userName[100];
    int count = 0;
    int capacity = 5;

    // Initial allocation
    Student *records = (Student *)malloc(capacity * sizeof(Student));
    if (!records) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Greeting
    printf("--- Welcome to the Student Record System ---\n");
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = 0;
    printf("Hello, %s!\n\n", userName);

    // Main menu for user's choice using loop and switch-statement
    int choice;
    do {
        printf("\nSelect from the menu options:\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Save Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();


        switch (choice) {
            case 1: 
                printf("[INFO] Add Student function called.\n");
                // addStudent(&records, &count, &capacity);
                break;
            case 2: 
                printf("[INFO] Search Student function called.\n");
                // searchRecord(records, count);
                break;
            case 3: 
                printf("[INFO] Save Records function called.\n");
                // saveToFile(records, count);
                break;
            case 4: 
                printf("Exiting system...\n");
                break;
            default: 
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    // ----------------- Function Implementations ----------------- (other members)

    free(records); // cleanup
    printf("Memory freed. Goodbye!\n");
    return 0;
}

