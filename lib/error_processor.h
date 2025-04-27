#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include <my_structs.h>

#include <perror2.h>

/**
 * Brief:
 * Processes errors related to command line arguments.
 *
 * Description:
 * This function checks for various error conditions based on the command line
 * argument status provided by the 'ArgumentCheck' and 'ArgumentValues' structures.
 * It checks if any of the errors have occurred and
 * prints error messages using the 'Perror2' function
 *
 * Parametrs:
 * global_error - a boolean indicating if a global error has already occurred
 *                     (needs to if an error message has been printed before)
 * arg_check - a structure containing flags indicating which command line 
 *                  arguments were provided by the user
 * arg_values - a structure containing the actual values of the arguments
 *                   provided by the user
 *
 * Return values: 
 * Returns true if an error has occurred and prints error 
 * messages; otherwise, returns false if no
 * errors were detected.
 *
 * Details:
 * The function performs the following checks:
 * - If 'global_error' is true, it returns true immediately as an error was
 *   already reported
 * - If any of log or argument errors occured it return Perror2 message
 *   with code from 700 up to 703
 * - Returns false if no error conditions are met.
 *
 * Note:
 * This function is intended to be called after command line arguments have been
 * parsed and validated to ensure users receive feedback for any issues with
 * their input.
 */

bool ErrorProcess(const bool global_error, const ArgumentCheck arg_check, const ArgumentValues arg_values);