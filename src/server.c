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
#include<unistd.h>          // for sleep

#include "students.h"
#include "student-data.h"
#include "shared-memory.h"

#define TRUE 1
#define FALSE 0
#define NSECS 30		        // number of seconds to live

int main() {

    // Initialize tracking changes
    int changesMade = FALSE;

    // Initialize Student Data
    struct students student_data;
    if (student_data_exists())
    {
        student_data = student_data_load();
    }
    else {
        student_data = student_data_init();
        changesMade = TRUE;
    }
    
    // Create the shared memory
    setup_shared_memory();
    
    // Loop to poll activity and update data
    int counter = 30;
    while ( counter > 0 )
    {
        // Run who command to get all active users

        // Loop through all users in student data
            // If user is in active list
                // If user status is active
                    // Do nothing
                // If user status is inactive
                    // Set user status to active
                    // Update last login time
            // If user is not in active list
                // If user status is active
                    // Set user to inactive
                    // Calculate how long they were on the server
                // If user status is inactive
                    // Do nothing

        // Update the shared memory
        cpy_student_data_to_shared_memory(student_data);

        // Save the data after making any changes
        if (changesMade)
        {
            student_data_save(student_data);
            changesMade = FALSE;
        }

        counter--;
        sleep(1);
    }

    printf("%n", student_data.students[0].userID);

    // Detach the shared memory
    detach_shared_memory();

    // Exit Successfully
    return 0;
}
