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