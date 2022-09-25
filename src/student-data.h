/**
 * @file studentData.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief 
 * 
 */

#include "students.h"

/**
 * @brief Loads data from the storage file
 * 
 */
struct students student_data_load();

/**
 * @brief Saves the given student data to storage file, in csv format
 * 
 */
void student_data_save(struct students studentData);

/**
 * @brief Checks if there is a data file already present
 * 
 * @return int File Exists (1), File does not Exist (2)
 */
int student_data_exists();

/**
 * @brief Generates randomized student data
 * 
 * @return struct students 
 */
struct students student_data_init();