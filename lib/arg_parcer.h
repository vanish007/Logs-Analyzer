#pragma once

#include <iostream>

#include <my_structs.h>

#include <validator.h>
#include <perror2.h>
#include <string_to_int.h>
/**
 * Brief:
 * Parses command line arguments and saves it into structures
 * 
 * Description:
 * This function processes each command line argument passed to the program. 
 * After, it validates each argument using the "Validate" function and 
 * if everything is corrects saves the values of arguments into 
 * ArgumentValues struct. Also switches flags in ArgumentCheck 
 * from false to true. If any errors are encountered during parsing or validation, 
 * appropriate error messages are printed using "Perror2" function 
 * and the "global_error" flag is set to true
 * 
 * Parametrs:
 * argc - the number of command line arguments
 * argv - the array of command line arguments
 * arg_check - the structure to hold flags for corresponding arguments
 * arg_values - the structure to store values corresponding to arguments
 * global_error - a reference to a boolean flag from main.cpp
 */
void ArgParce(int argc, char* argv[], ArgumentCheck& arg_check, 
                ArgumentValues& arg_values, bool& global_error);