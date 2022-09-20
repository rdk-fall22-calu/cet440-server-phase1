/**
 * @file studentData.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief 
 * 
 */

#include "students.h"
#include "student.h"

/**
 * @brief 
 * 
 */
struct students student_file_load();

/**
 * @brief 
 * 
 */
void student_file_save(struct students studentData);

/**
 * @brief Checks if the 
 * 
 * @return int 
 */
int student_file_exists();


struct students student_data_init();