#include "student.h"

void saveToFile(Student *students, int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Failed to open file for saving");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%lf\n", students[i].rollNumber, students[i].name, students[i].marks);
    }

    fclose(file);
    printf("Saved %d students to %s\n", count, FILE_NAME);
}

void loadFromFile(Student **students, int *count, int *capacity) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No data file found (%s) → starting empty.\n", FILE_NAME);
        return;  // No crash - just return with empty array
    }

    // Clear any existing data (prevent duplicates on reload)
    free(*students);
    *students = NULL;
    *count = 0;
    *capacity = INITIAL_CAPACITY;
    *students = (Student *)malloc(*capacity * sizeof(Student));
    if (*students == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return;
    }

    char line[256];  // Buffer for each line
    int loaded = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strlen(line) < 3) continue;  // Skip empty/short lines

        int rollNumber;
        char name[MAX_NAME_LENGTH];
        double marks;

        // Parse line (sscanf handles commas and trims whitespace implicitly for %s)
        if (sscanf(line, "%d , %99[^,] , %lf", &rollNumber, name, &marks) == 3 ||
            sscanf(line, "%d,%99[^,],%lf", &rollNumber, name, &marks) == 3) {
            // Resize if needed
            if (*count >= *capacity) {
                *capacity *= 2;
                *students = (Student *)realloc(*students, *capacity * sizeof(Student));
                if (*students == NULL) {
                    perror("Failed to reallocate memory");
                    fclose(file);
                    return;
                }
            }

            // Add student
            (*students)[*count].rollNumber = rollNumber;
            strncpy((*students)[*count].name, name, MAX_NAME_LENGTH - 1);
            (*students)[*count].name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null-terminated
            (*students)[*count].marks = marks;
            (*count)++;
            loaded++;
        } else {
            fprintf(stderr, "Skipping invalid line: %s", line);
        }
    }

        fclose(file);

        printf("Loaded %d students from %s\n", loaded, FILE_NAME);

    }

    

    void addStudent(Student **records, int *count, int *capacity) {

        if (*count >= *capacity) {

            *capacity = (*capacity == 0) ? INITIAL_CAPACITY : *capacity * 2;

            *records = (Student *)realloc(*records, *capacity * sizeof(Student));

            if (*records == NULL) {

                perror("Memory allocation failed");

                exit(1);

            }

        }

    

        Student newStudent;

        int roll;

        

        while (1) {

            printf("Enter Roll Number: ");

            if (scanf("%d", &roll) != 1) {

                printf("[!] Invalid input. Please enter a number.\n");

                while (getchar() != '\n'); // clear buffer

                continue;

            }

            getchar(); // consume newline

    

            if (!isRollNumberUnique(*records, *count, roll)) {

                printf("[!] Roll Number %d already exists. Try again.\n", roll);

                continue;

            }

            break;

        }

        newStudent.rollNumber = roll;

    

        printf("Enter Name: ");

        fgets(newStudent.name, MAX_NAME_LENGTH, stdin);

        newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    

        double marks;

        while (1) {

            printf("Enter Marks (0-100): ");

            if (scanf("%lf", &marks) != 1) {

                printf("[!] Invalid input. Please enter a number.\n");

                while (getchar() != '\n');

                continue;

            }

            getchar();

    

            if (!isValidMarks(marks)) {

                printf("[!] Marks must be between 0 and 100. Try again.\n");

                continue;

            }

            break;

        }

        newStudent.marks = marks;

    

        (*records)[*count] = newStudent;

        (*count)++;

        printf("\n[+] Student added successfully.\n");

    }

    

    void modifyRecord(Student *records, int count) {

        if (count == 0) {

            printf("\n[!] No records to modify.\n");

            return;

        }

    

        int roll;

        printf("Enter Roll Number to modify: ");

        scanf("%d", &roll);

        getchar();

    

        int index = -1;

        for (int i = 0; i < count; i++) {

            if (records[i].rollNumber == roll) {

                index = i;

                break;

            }

        }

    

        if (index == -1) {

            printf("\n[!] Student not found.\n");

            return;

        }

    

        printf("Current Name: %s\n", records[index].name);

        printf("Enter New Name (leave blank to keep current): ");

        char newName[MAX_NAME_LENGTH];

        fgets(newName, MAX_NAME_LENGTH, stdin);

        newName[strcspn(newName, "\n")] = 0;

        if (strlen(newName) > 0) {

            strcpy(records[index].name, newName);

        }

    

        printf("Current Marks: %.2f\n", records[index].marks);

        printf("Enter New Marks (negative to keep current): ");

        double newMarks;

        if (scanf("%lf", &newMarks) == 1 && newMarks >= 0) {

            if (isValidMarks(newMarks)) {

                records[index].marks = newMarks;

            } else {

                printf("[!] Invalid marks. Kept current.\n");

            }

        }

        getchar();

        printf("\n[+] Record updated.\n");

    }

    