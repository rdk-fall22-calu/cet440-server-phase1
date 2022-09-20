# CET 440 - Server - Phase 1

This is the source code for the first phase of the project for CET 440.

To compile, use the ==make== command with the provided Makefile.

---

The Student Struct for this project is defined in [student.h](src/student.h).
It is defined as:

| Type          | Name              | Description                                           |
| ------------  | ------------      | --------------------------------------------------    |
| char *        | userID            | User ID, as the PennWest Email ID                     |
| char *        | name              | Name of the user, in "FirstName LastName" format      |
| int           | age               | Age of the user, random integer (18-22)               |
| float         | gpa               | GPA of the user, random float (2.5-4)                 |
| int           | status            | Whether the user is active (1) or inactive (0)        |
| time_t        | lastLoginTime     | Last time the user was logged into the server         |
| time_t        | totalActiveTime   | Total amount of time the user was logged in           |

The shared memory for this project is defined in [students.h](src/students.h).
It is defined as an array of ==Student==, as specified above.