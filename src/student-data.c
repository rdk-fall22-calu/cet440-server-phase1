/**
 * @file studentfile.c
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Handles the loading from and saving to the persistent student data storage
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "students.h"
#include "string.h"

#define NAMES_FILE "names.txt"
#define FILE_NAME "student_data.csv"
#define FILE_EXISTS 1
#define FILE_NOT_EXIST 0
#define FILE_READ "r"
#define FILE_WRITE "w"
#define FILE_BUFFER_SIZE 50
#define DELIMITER ","

struct students student_data_load()
{
    // Open the file
    FILE* studentFile = fopen(FILE_NAME, FILE_READ);
    
    // Init tokenizer
    char *token;

    // Init Student Data
    int currentStudent = 0;
    struct students studentData;
    
    // Loop for data in file
    char line[FILE_BUFFER_SIZE];
    while (fgets(line, FILE_BUFFER_SIZE, studentFile) != NULL)
    {
        token = strtok(line, DELIMITER);

        // Get the User ID
        strcpy(studentData.students[currentStudent].userID, token);

        // Get the Name
        token = strtok(NULL, DELIMITER);
        strcpy(studentData.students[currentStudent].name, token);

        // Get the Age
        token = strtok(NULL, DELIMITER);
        studentData.students[currentStudent].age = atoi(token);

        // Get the GPA
        token = strtok(NULL, DELIMITER);
        studentData.students[currentStudent].gpa = atof(token);

        // Get the Status
        token = strtok(NULL, DELIMITER);
        studentData.students[currentStudent].status = atoi(token);

        // Get the Last Login Time
        token = strtok(NULL, DELIMITER);
        studentData.students[currentStudent].lastLoginTime = atoi(token);

        // Get the Total Time Active
        token = strtok(NULL, DELIMITER);
        studentData.students[currentStudent].totalActiveTime = atoi(token);
        
        // Increment Student Counter
        currentStudent++;
    }   

    // Close the File
    fclose(studentFile);

    // Return the data
    return studentData;
}


void student_data_save(struct students studentData)
{
    // Open the file
    FILE* studentFile = fopen(FILE_NAME, FILE_WRITE);

    // For each student, write out the data
    int i;
    for (i = 0; i < 27; i++)
    {
        fprintf(studentFile, "%s,%s,%d,%1.1f,%d,%d,%d\n",
            studentData.students[i].userID,
            studentData.students[i].name,
            studentData.students[i].age,
            studentData.students[i].gpa,
            studentData.students[i].status,
            studentData.students[i].lastLoginTime,
            studentData.students[i].totalActiveTime);
    }

    // Close the file
    fclose(studentFile);
}


int student_data_exists()
{
    FILE* in_file = fopen(FILE_NAME, FILE_READ);
    if (!in_file)
        return FILE_NOT_EXIST;
    fclose(in_file);
    return FILE_EXISTS;
}



struct students student_data_init()
{
    // Init Student Data
    struct students studentData;
    
    // Open Names File
    FILE* namesFile = fopen(NAMES_FILE, FILE_READ);
    
    // Loop for data in file
    char line[FILE_BUFFER_SIZE];
    char *token;
    srand(time(0));

    int currentStudent = 0;
    while (fgets(line, FILE_BUFFER_SIZE, namesFile) != NULL)
    {
        token = strtok(line, " ");
        strcpy(studentData.students[currentStudent].userID, token);
        
        token = strtok(NULL, "\n");
        strcpy(studentData.students[currentStudent].name, token);
        
        studentData.students[currentStudent].age = (rand() % 5) +18;
        
        studentData.students[currentStudent].gpa = rand() % 16 + 25;
        studentData.students[currentStudent].gpa /= 10;
           
        studentData.students[currentStudent].status = 0;
       
        studentData.students[currentStudent].lastLoginTime = 0; 
        
        studentData.students[currentStudent].totalActiveTime = 0;
        
        currentStudent++;
    }

    // Close the file
    fclose(namesFile);

    // Return data
    return studentData;

}