#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include <my_structs.h>
/**
 * Description:
 * This function outputs the values of various arguments to the console
 *
 * Parametrs:
 * arg_check - structure containing flags or checks for each argument type.
 * arg_values - structure containing the values for each argument type.
 *
 * The function will display arguments and its value
 */

void StatsViewe(const ArgumentCheck arg_check, const ArgumentValues arg_values);
