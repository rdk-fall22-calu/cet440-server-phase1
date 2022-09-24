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
#include<unistd.h>          // for sleep

#include "students.h"
#include "studentData.h"

#define TRUE 1
#define FALSE 0

#define shmkey 0x7700 + 01      //key for shmget()
#define IPC_RESULT_ERROR (-1)   //error returning -1 if sharded id could not be created
#define NSECS 30		        // number of seconds to live

int main() {

    // Initialize tracking changes
    int changesMade = FALSE;

    // Initialize Student Data
    struct students studentData;
    if (student_data_exists())
    {
        studentData = student_data_load();
    }
    else {
        studentData = student_data_init();
        changesMade = TRUE;
    }

    // Create the Shared Memory space for student data
    int shared_memory_id;
    int shared_memory_address;
    struct student *structure_address;
    
    //Create shared memory id
    shared_memory_id = shmget(shmkey, sizeof(struct student), IPC_CREAT | 0666);    //assign key to id
    if(shared_memory_id == IPC_RESULT_ERROR){                                       //error check 
        printf("Error: shmget() failed, errno = %i\n", errno);
        perror("shmget()");
    }
    else
        printf("shmget() successful, shared_memory_id = %i\n", shared_memory_id);
    
    //allocate shared memory 
    shared_memory_address = (int) shmat( shared_memory_id, 0, 0 );          //allocate shared memory
    structure_address= (struct student *) shmat( shared_memory_id, 0, 0 );  //attach student structure to shared memory

    printf( "shm_addr = 0x%08x, structure_address = 0x%08x\n", shared_memory_address, structure_address );
    if ( (int) structure_address == IPC_RESULT_ERROR )		                // check shmat() return value
    {
        printf( "Error: shmat() failed, errno = %i\n", errno );
        perror( "shmat()" );
    }
    
    //copy data to allocated memory 
    
    //wait to allow client to read shared memory
    printf( "\nSleeping for %i seconds.\n\n", NSECS );
    sleep( NSECS );
    printf( "\nCompleted.\n\n" );
    
    //Detach shared memory
    if ( shmctl( shared_memory_id, IPC_RMID, NULL ) == IPC_RESULT_ERROR )
    {
        printf( "Error: shmctl(IPC_RMID) failed, errno = %i\n", errno );
        perror( "shmctl(IPC_RMID)" );
        exit( IPC_RESULT_ERROR );
    }
    
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
                    // Update last login time
            // If user is not in active list
                // If user status is active
                    // Set user to inactive
                    // Calculate how long they were on the server
                // If user status is inactive
                    // Do nothing


        // Save the data after making any changes
        if (changesMade)
        {
            student_data_save(studentData);
            changesMade = FALSE;
        }
    }

    // Exit Successfully
    return 0;
}
