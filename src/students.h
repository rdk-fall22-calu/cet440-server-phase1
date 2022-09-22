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

struct student {

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
    time_t totalActiveTime;

};

struct students {
    struct student students[27];
};

#endif 