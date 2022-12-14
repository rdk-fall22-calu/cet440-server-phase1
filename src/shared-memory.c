/**
 * @file shared-memory.c
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Management of Shared Memory
 * 
 */

#ifndef __SHARED_MEMORY_C__
#define __SHARED_MEMORY_C__

#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "shared-memory.h"
#include "students.h"

static int shared_memory_address;
static int shared_memory_id;
static struct students *shared_data;


void setup_shared_memory()
{
    // Get the ID for the shared memory
    shared_memory_id = shmget(SHARED_MEMORY_KEY, sizeof(struct students), IPC_CREAT | 0666);
    
    // Ensure the shared memory ID was created 
    if (shared_memory_id == IPC_RESULT_ERROR){                                        
        fprintf("Error: shmget() failed, errno = %i\n", errno);
        perror("shmget()");
    }
    //else
        //printf("shmget() successful, shared_memory_id = %i\n", shared_memory_id);

    // Allocate the shared memory
    shared_memory_address = (int) shmat( shared_memory_id, 0, 0 );
    shared_data = (struct students *) shmat( shared_memory_id, 0, 0 );
    
    // Check shared memory created successfully
    if ( (int) shared_data == IPC_RESULT_ERROR )		                
        {
            printf( "Error: shmat() failed, errno = %i\n", errno );
            perror( "shmat()" );
        }
}


int detach_shared_memory()
{
    // Check if memory is cleared correctly
    if ( shmctl( shared_memory_id, IPC_RMID, NULL) == IPC_RESULT_ERROR )
    {
        printf( "Error: shmctl(IPC_RMID) failed, errno = %i\n", errno );
        perror( "shmctl(IPC_RMID)" );
        // Unsuccessful
        return 0;
    }

    // Detached Memory Successfully
    return 1;
}


void cpy_student_data_to_shared_memory(struct students students)
{
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        strcpy(shared_data->students[i].userID, students.students[i].userID);
        strcpy(shared_data->students[i].name, students.students[i].name);

        shared_data->students[i].age = students.students[i].age;
        shared_data->students[i].gpa = students.students[i].gpa;
        shared_data->students[i].lastLoginTime = students.students[i].lastLoginTime;
        shared_data->students[i].totalActiveTime = students.students[i].totalActiveTime;
        shared_data->students[i].status = students.students[i].status;

        /*
        printf("%s %s %d %d %d %d %d\n",
            shared_data->students[i].userID,
            shared_data->students[i].name,
            shared_data->students[i].age,
            shared_data->students[i].gpa,
            shared_data->students[i].lastLoginTime,
            shared_data->students[i].totalActiveTime,
            shared_data->students[i].status);
        */
    }
}

#endif