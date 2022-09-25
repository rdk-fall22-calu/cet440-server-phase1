/**
 * @file shared-memory.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Management of Shared Memory
 * 
 */

#ifndef __SHARED_MEMORY_H__
#define __SHARED_MEMORY_H__

#define SHARED_MEMORY_KEY 0x7700 + 01
#define IPC_RESULT_ERROR (-1)           // error returning -1 if sharded id could not be created

#include "students.h"

void setup_shared_memory();
int detach_shared_memory();
void cpy_student_data_to_shared_memory(struct students students);

#endif