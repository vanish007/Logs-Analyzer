#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <deque>

#include <my_structs.h>

#include <strcmp2.h>
#include <perror2.h>
#include <string_to_int.h>
#include <string_concatenator.h>
#include <strlen2.h>
#include <log_processor.h>
#include <local_time_parcer.h>

/**
 * Description:
 * This function computes a hash value for a given C-style string using a simple 
 * hash algorithm. The result is always a non-negative integer.
 * 
 * Parametrs:
 * s - a pointer to the C-style string to hash.
 * 
 * Return values:
 * An integer hash value for the input string.
 */
int Hesh(const char* s);
/**
 * Desxription:
 * This function is used to compare two pairs where the key is 
 * a C-style string
 * and the value is an int. It compares the pairs based on their 
 * second elements (the integers)
 * in descending order.
 * 
 * Parameters:
 * a - the first pair to compare.
 * b - the second pair to compare.
 * 
 * Return values:
 *  true if the second element of 'a' is greater than the second element of 'b'.
 *  false otherwise.
 */
bool compareBySecond(const std::pair<const char*, int>& a, 
                    const std::pair<const char*, int>& b);

/**
 * Brief:
 * Parses log files and processes the logs according to specified arguments.
 * 
 * Description:
 * This function reads log data from a log file, processes 
 * it according to the provided argument
 * checks and values, and outputs processed information to
 *  both the console and an output file.
 *
 * The function handles log filtering based on time range and 
 * computes statistics for HTTP 5xx
 * status codes, including the number of occurrences of specific requests. 
 * It also determines
 * periods with the maximum number of requests within a specified time window.
 * 
 * Parametrs:
 * arg_check An instance of ArgumentCheck structure used to 
 * specify which processing and output operations to perform.
 * arg_values An instance of ArgumentValues structure containing values
 *  for arguments, such as file paths, time windows, and statistics limits.
 */
void LogParce(const ArgumentCheck arg_check, const ArgumentValues arg_values, 
                std::ifstream& fin, std::ofstream& fout);