#include <stdio.h>
#include "student.h"

// member 4:search and Analytics
// 1.the "print" function.
//this builds the table member 4 is responsible for
//it also handles the pass/fail logic on the go.
void displayRecords(Student *records, int count) {
//if the database is empty, let the user know so they don't see a blank table.
    if (count == 0) {
printf("\n[!] No student records to display.\n");
return;
}

//creating a clean header for the table
printf("\n%-10s %-20s %-10s %-10s\n", "Roll No", "Name", "Marks", "Result");
printf("----------------------------------------------------------\n");

for (int i = 0; i < count; i++) {
// Result logic: pass if marks > 40
char *status = (records[i].marks >= 40) ? "Pass" : "Fail";

//print the row. %-20s keeps the names aligned even if they become too long.
printf("%-10d %-20s %-10.2f %-10s\n",
records[i].rollNumber,
records[i].name,
records[i].marks,
status);
}
printf("----------------------------------------------------------\n");
}

// 2. search logic.
//this looks through the array one by one to find a match.
int searchRecord(Student *records, int count, int targetRoll) {
for (int i = 0; i < count; i++) {
    // If we find a match,give the index back to the main menu.
if (records[i].rollNumber == targetRoll) {
return i; // Return the index for the main loop to use
}
}
//If we finish the loop and find nothing,return -1 as an error code.
return -1; // Not found
}

// 3.Class Analytics
//This calculates the average  for the whole group.
double calculateAverage(Student *records, int count) {
if (count == 0) {
return 0.0;
}

double sum = 0.0;
for (int i = 0; i < count; i++) {
sum += records[i].marks;
}

//Divide the total by the number of students to get the average.
return sum / (double)count;
}
