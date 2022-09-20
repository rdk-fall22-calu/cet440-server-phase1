/**
 * @file server.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Entry Point for the Server
 * 
 */

#include <stdio.h>		    // for standard system I/O stuff
#include <errno.h>		    // for error handling on system call
#include <sys/types.h>		// for system defined types
//#include <sys/ipc.h>		// for IPC permission structure
//#include <sys/shm.h>		// for shared memory facility defines


#include "students.h"
#include "student.h"
#include "studentData.h"

int main() {

    // Initialize the Logger

    // Initialize Student Data
    struct students studentData;
    if (student_file_exists)
        studentData = student_file_load();
    else {
        studentData = student_data_init();
    }

    // Create the Shared Memory space for student data

    // Loop to poll activity and update data

    // Cleanup
    student_file_save(studentData);

    // Exit Successfully
    return 0;
}