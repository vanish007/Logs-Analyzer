#pragma once

#include <strcmp2.h>

/**
 * Description:
 * Converts a three-letter month abbreviation to its corresponding number.
 *
 * Parametrs:
 * month - a pointer to a null-terminated string that represents the 
 *              abbreviated month name (e.g., "Jan", "Feb", "Mar", etc.).
 * Return values:
 * An integer corresponding to the month (1 for January, ..., 12 for December).
 * Returns -1 if the input does not match any valid month abbreviation.
 * 
 * Example:
 * MonthToNum("Jan") will return 1;
 * MonthToNum("Dec") will return 12;
 * MonthToNum("Jec") will return -1;
 */
int MonthToNum(const char* month);