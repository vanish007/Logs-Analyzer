#pragma once

#include <string_to_int.h>
#include <month_to_num.h>
#include <month_to_days.h>

/**
 * Description:
 * Gets a date in timestamp format and return an integer that
 * represent amount of second passed from Jan 1 1970
 * 
 * Parametrs:
 * Local_time - null-terminated string 
 *              in format [DD:MONTH:YYYY:HH:MM:SS -0000] -0000 is UTC 
 *              first two numbers are hours. last two are minutes
 * 
 * Return values:
 * Amount of second passed from Jan 1 1970
 * 
 * Example:
 * [30:SEP:2024:18:09:45 +0300] returns 1727708985
 * 
 * Note:
 * month name should be written using first 3 letters of a month
 */
int LocalTimeParce(const char local_time[], const int kLocalTimeSize);