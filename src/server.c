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
#include <sys/ipc.h>		// for IPC permission structure
#include <sys/shm.h>		// for shared memory facility defines

#include "students.h"
#include "studentData.h"

#define size 4096 //block memory size
#define shmkey 0x7700 + 01 //key for shmget()
#define IPC_RESULT_ERROR (-1) //error returning -1 if sharded id could not be created

int main() {

    // Initialize Student Data
    struct students studentData;
    if (student_data_exists())
    {
        studentData = student_data_load();
    }
    else {
        studentData = student_data_init();
    }

    // Create the Shared Memory space for student data
    int shared_memory_id;
    shared_memory_id = shmget(shmkey, size, IPC_CREAT | 0666);
    if(shared_memory_id == IPC_RESULT_ERROR){
        printf("Error: shmget() failed, errno = %i\n", errno);
        perror("shmget()");
    }
    else
        printf("shmget() successful, shared_memory_id = %i\n", shared_memory_id);

    // Loop to poll activity and update data
    while ( 1 )
    {
        // Run who command to get all active users

        // Loop through all users in student data
            // If user is in active list
                // If user status is active
                    // Do nothing
                // If user status is inactive
                    // Set user status to active
            // If user is not in active list
                // If user status is active
                    // Set user to inactive
                    // Calculate how long they were on the server
                // If user status is inactive
                    // Do nothing


        // Save the data after making any changes
        student_data_save(studentData);
    }

    // Exit Successfully
    return 0;
}