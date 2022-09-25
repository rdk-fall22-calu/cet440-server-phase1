/**
 * @file students.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Defines the students struct, representing the structure of the specified shared memory
 * 
 */

#ifndef __STUDENTS_H__
#define __STUDENTS_H__

#include <time.h>

#define ACTIVE 1
#define INACTIVE 0

#define NUM_STUDENTS 27

typedef struct student {

    // User ID, the PennWest Email ID
    char userID[10];
    
    // Name of the User, in "FirstName LastName" format
    char name[50];

    // Random Age, interval [18,22]
    int age;

    // Random GPA, interval [2.5,4]
    float gpa;

    // Active Status, boolean value, ACTIVE/INACTIVE
    int status;

    // Last Time Logged into Server
    time_t lastLoginTime;

    // Total Time spent Active on Server
    int totalActiveTime;

} Student;

struct students {
    struct student students[NUM_STUDENTS];
};


int student_is_active(struct student s);
int student_set_active(struct student s);
int student_set_inactive(struct student s);


#endif 