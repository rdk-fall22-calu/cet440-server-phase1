/**
 * @file students.c
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Defines the students functions
 * 
 */

#ifndef __STUDENTS_C__
#define __STUDENTS_C__

#include "students.h"
#include <time.h>

int student_is_active(struct student s)
{
    return s.status;
}

int student_set_active(struct student s)
{
    s.status = ACTIVE;
    s.lastLoginTime = time(NULL);
}

int student_set_inactive(struct student s)
{
    s.status = INACTIVE;
    s.totalActiveTime += time(NULL) - s.lastLoginTime;
}

void copy_student(struct student s1, struct student s2)
{
    strcpy(s2.userID, s1.userID);
    strcpy(s2.name, s1.name);
    s2.age = s1.age;
    s2.gpa = s1.gpa;
    s2.status = s1.status;
    s2.lastLoginTime = s1.lastLoginTime;
    s2.totalActiveTime = s1.totalActiveTime;
}


#endif