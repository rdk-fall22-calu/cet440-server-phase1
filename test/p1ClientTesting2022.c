#include <stdio.h>              // for standard system I/O stuff
#include "students.h"

#define SHMKEY 0x77000 + 01  //change to your key


void printstruct(struct student x[NUM_STUDENTS]);
 
int main(){
    struct students *y;
	int i;
	float avgGPA=0, avgAge=0;
	int stutoday=0, stuyest=0, stubefyest=0;
	int shm_id=0;	
	struct student students_read[NUM_STUDENTS];

    if (shm_id == 0) 
        shm_id = shmget(SHMKEY,0,0);;
	printf( "shmat created \n");

	if(shm_id == -1){
		printf("Error, could not get the shared memory id\n");
		exit(-1);
	}
	else
	{
        y= (struct students *) shmat( shm_id, 0, 0 );
	}

	for (i = 0; i < NUM_STUDENTS; i++)
	{
		printf("Printing student %d", i);
		printf("%s %s %d %d %d %d %d\n",
		y->students[i].userID,
		y->students[i].name,
		y->students[i].age,
		y->students[i].gpa,
		y->students[i].lastLoginTime,
		y->students[i].totalActiveTime,
		y->students[i].status);
	}

/*
    for(i = 0;i<NUM_STUDENTS;i++)
    {
    	strcpy(students_read[i].userID,y->students[i].userID) ;
    	strcpy(students_read[i].name, y->students[i].name);
    	students_read[i].age = y->students[i].age;
    	students_read[i].gpa = y->students[i].gpa;
    	students_read[i].status = y->students[i].status;
    	students_read[i].lastLoginTime = y->students[i].lastLoginTime;
    	students_read[i].totalActiveTime = y->students[i].totalActiveTime;
    }
	printstruct(students_read);
*/	
    shmdt( (void *) y );

    return( 0 );
}

void printstruct(struct student x[NUM_STUDENTS])
{
	int i;
	for(i = 0; i < NUM_STUDENTS; i++)
	{
		printf("students_read[%d].id = %s\n",i,x[i].userID);
		printf("students_read[%d].name = %s\n",i,x[i].name);
		printf("students_read[%d].age = %d\n",i,x[i].age);
		printf("students_read[%d].gpa = %f\n",i,x[i].gpa);
		printf("students_read[%d].status = %d\n",i,x[i].status);
		printf("students_read[%d].lastlogged = %d\n",i,x[i].lastLoginTime);
		printf("students_read[%d].totalActiveTime = %s\n",i,x[i].totalActiveTime);
	}
}
