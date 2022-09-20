/**
 * @file logger.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Defines the student struct according to specifications
 * 
 */

#include <stdio.h>
#include <string.h>

// Logging Levels
#define INFO 0
#define ERROR 1
#define WARNING 2

/**
 * @brief Writes a message to console based on the level specificed
 * 
 * @param level The level to log the message at
 * @param message The message to log
 */
void log_message(int level, char *message);

/**
 * @brief Opens the log file to write to
 * 
 * @return int Success (1) / Failure (0)
 */
int log_init();

/**
 * @brief Closes the log file
 * 
 * @return int Success (1) / Failure (0)
 */
int log_close();
