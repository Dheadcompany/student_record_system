#include "student.h"

int main() {
    Student *students = NULL;
    int count = 0;
    int capacity = 0;

    // Load at program start (your load function)
    loadFromFile(&students, &count, &capacity);

    // Add some students (example - replace with your team's add function)
    // Resize if needed
    if (count >= capacity) {
        capacity = capacity ? capacity * 2 : INITIAL_CAPACITY;
        students = (Student *)realloc(students, capacity * sizeof(Student));
    }
    students[count].rollNumber = 1;
    strcpy(students[count].name, "Emmanuel");
    students[count].marks = 85.5;
    count++;

    if (count >= capacity) {
        capacity *= 2;
        students = (Student *)realloc(students, capacity * sizeof(Student));
    }
    students[count].rollNumber = 2;
    strcpy(students[count].name, "Aisha");
    students[count].marks = 92.0;
    count++;

    // Display current students (example - for testing)
    printf("\nCurrent students:\n");
    for (int i = 0; i < count; i++) {
        printf("%d, %s, %.1f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }

    // Save (your save function)
    saveToFile(students, count);

    // Free memory (as per template)
    free(students);

    printf("Program finished.\n");
    return 0;
}