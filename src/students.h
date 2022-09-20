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

#include "student.h"

struct students {
    struct student students[27];
};

#endif 