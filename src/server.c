/**
 * @file server.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Entry Point for the Server
 * 
 */

#include <stdio.h>		    // for standard system I/O stuff
#include <stdlib.h>
#include <string.h>
#include <errno.h>		    // for error handling on system call
#include <sys/types.h>		// for system defined types
#include <unistd.h>          // for sleep

#include "students.h"
#include "student-data.h"
#include "shared-memory.h"

#define TRUE 1
#define FALSE 0
#define NSECS 30		        // number of seconds to live

int main() {

    // Initialize tracking changes
    int changes_made = FALSE;

    // Initialize Student Data
    struct students student_data;
    if (student_data_exists())
    {
        student_data = student_data_load();
    }
    else {
        student_data = student_data_init();
    }
    changes_made = TRUE;
    
    // Create the shared memory
    setup_shared_memory();

    // Setup who command piping to obtain active users list
    int active_users_count = 0;
    char active_users[50][10];
    FILE *fpipe;
    char *command = "who";
    char result[1024] = {0x0};
   
    // Loop to poll activity and update data
    while ( TRUE )
    {
        // Run who command to get all active users
        if ( 0 == (fpipe = (FILE*)popen(command, "r")))
        {
            perror("popen() failed.");
            exit(EXIT_FAILURE);
        }

        active_users_count = 0;
        while( fgets(result, sizeof(result), fpipe) != NULL )
        {
            char *token;
            token = strtok(result, " \t");
            strcpy(active_users[active_users_count], token);
            active_users_count++;
        }
        
        pclose(fpipe);

        // Loop through all users in student data
        for (int i = 0; i < NUM_STUDENTS; i++)
        {
            struct student student = student_data.students[i];
            printf("Student: %s \n", student.name );
            for (int j = 0; j < active_users_count; j++)
            {
                char *user = active_users[i];
                printf("User: %s \n", user );
                if (strcmp(student.userID, user) == 0)
                {
                    if (student.status == INACTIVE)
                    {
                        student_set_active(student);
                        changes_made = TRUE;
                    }
                } 
                else 
                {
                    if (student.status == ACTIVE)
                    {
                        student_set_inactive(student);
                        changes_made = TRUE;
                    }
                }
            }
        }

        // Save the data after making any changes
        if (changes_made)
        {
            student_data_save(student_data);
            changes_made = FALSE;
        }

        // Update the shared memory
        cpy_student_data_to_shared_memory(student_data);

        // Sleep for 1 second
        sleep(1);
    }

    // Detach the shared memory
    detach_shared_memory();

    // Exit Successfully
    return 0;
}
