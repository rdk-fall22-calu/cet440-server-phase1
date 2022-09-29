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
#include <string.h>

int student_is_active(struct student s)
{
    return s.status;
}

int student_set_active(struct student *s)
{
    s->status = ACTIVE;
    s->lastLoginTime = time(0);
    printf("%s set to status %d at time %d", s->userID, s->status, s->lastLoginTime);
}

int student_set_inactive(struct student *s)
{
    s->status = INACTIVE;
}


#endif