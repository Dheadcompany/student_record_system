Control flow architecture

START
 ↓
Display Welcome Message
 ↓
Initialize Data (array or dynamic memory)
 ↓
DO
    Display Menu
    Read User Choice
    SWITCH (choice)
        1 → Add Student
        2 → Search Student
        3 → Save Records
        4 → Exit → free memory and terminate
        DEFAULT → invalid input
WHILE choice != 4
 ↓
END
 
 Loop continues until user selects Exit (4)
 Menu allows navigation between different operations
 Invalid input is handled gracefully

Add Student 

. Increment student count
. Reallocate dynamic memory for new student
. Prompt user:
    - Enter student name
    - Enter roll number
    - Enter marks
. Determine pass/fail:
    - If marks >= 40 → Pass
    - Else → Fail
. Store student record in array
. Display confirmation message
. Return to Main Menu

Search Student 

. Prompt user for roll number
. Iterate through student array
. IF roll number found:
    - Display student details (name, roll number, marks, status)
. ELSE
    - Display "Student not found"
. Return to Main Menu

Save Records 

. Check if student count > 0
. Open file `students.txt` in write mode
. Write each student record to file
. Close file
. Display success message
. Return to Main Menu

Exit Program (Case 4)

. Free dynamically allocated memory
. Display goodbye message: "All memory freed. Exiting program. Goodbye!"
. Terminate program

Memory & Error Handling

. Dynamic memory allocation ensures the program can handle any number of students
. Memory is freed on program exit to prevent leaks
. Invalid menu choices are handled using the default case in switch
