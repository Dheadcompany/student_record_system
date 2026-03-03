#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================
// Data Architect & Core Structure
//   - Define the Student struct
//   - Initial greeting logic
//   - Initial malloc for the student array
//   - Final free() before program exits
// ============================================================


// --- Structure Definition ---
typedef struct {
    char name[100];
    int rollNumber;
    int marks;
} Student;


// --- Function Prototypes ---
void addStudent(Student **records, int *count, int *capacity);
void displayRecords(Student *records, int count);
void modifyRecord(Student *records, int count);
void searchRecord(Student *records, int count);
void calculateAverage(Student *records, int count);
void sortRecords(Student *records, int count);
void saveToFile(Student *records, int count);
void loadFromFile(Student **records, int *count, int *capacity);


int main() {
    char userName[100];
    int count = 0;
    int capacity = 5;

    // --- Memory Management: Initial allocation  ---
    Student *records = (Student *)malloc(capacity * sizeof(Student));
    if (records == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // --- Initial Greeting ---
    printf("--- Welcome to the Student Record System ---\n");
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = 0; // Strip trailing newline
    printf("Hello, %s!\n\n", userName);

    // --- Menu & Navigation: (Member 2) ---

    // --- Memory Management Final cleanup ---
    free(records);
    printf("System closed. Memory freed.\n");
    return 0;
}