#pragma once

#include <iostream>

/**
 * Description:
 * This function takes an integer error code and prints a 
 * message. It handles specific error codes related 
 * to various operational options and provides feedback to the user 
 * based on the error that occurred.
 *
 * Parametrs:
 * error_code - an integer representing the error code for which 
 *                   a message should be printed.
 *
 * The following error codes are handled:
 * - 100: Too many 'output' options
 * - 101: No output path specified
 * - 200: Too many 'print' options
 * - 300: Too many 'stats' options
 * - 301: 'Stats' option requires a number
 * - 302: Value for 'stats' option not provided
 * - 400: Too many 'window' options
 * - 401: 'Window' option requires a number
 * - 402: Value for 'window' option not provided
 * - 500: Too many 'from' options
 * - 501: 'From' option requires a number (>= 0)
 * - 502: Value for 'from' option not provided
 * - 600: Too many 'to' options
 * - 601: 'To' option requires a number (>= 0)
 * - 602: Value for 'to' option not provided
 * - 700: No operations specified, needs log file and options
 * - 701: No arguments provided
 * - 702: Too many log files specified
 * - 703: No log file specified, needs a file to process
 * - 800: Program could not find a log file to open
 * 
 * Note:
 * If an unrecognized error code is passed, a fatal error message 
 * will be printed.
 */
void Perror2(int error_code);
