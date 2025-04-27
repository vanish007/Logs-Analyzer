#pragma once

#include <numeric>

/** 
 * Description:
 * The MonthToDays function calculates the total number of days from the beginning 
 * of the year to the specified month, based on a standard non-leap year calendar. 
 * The months are represented by integers corresponding 
 * to their order in the calendar (1 for January, 2 for February, etc.)
 * 
 * Parameters:
 * month - an integer representing the month of the year. 
 *          it should be in the range from 1 to 12 (inclusive), where:
 * 1 = January
 * 2 = February
 * 3 = March
 * 4 = April
 * 5 = May
 * 6 = June
 * 7 = July
 * 8 = August
 * 9 = September
 * 10 = October
 * 11 = November
 * 12 = December
 *
 * Return Values:
 * - Returns an integer representing the total number of days from January 1st 
 *   to the last day of the specified month.
 * - If the month parameter is outside the range of 1 to 12, 
 *   the function will return 0 as the default value.
 *
 * Example:
 * MonthToDays(1) returns 0 
 * MonthToDays(2) returns 31 
 * MonthToDays(3) returns 59 
 * MonthToDays(4) returns 90 
 * MonthToDays(12) returns 335 
 * 
 * Note:
 * This function does not account for leap years; 
 * February is always considered to have 28 days
*/
int MonthToDays(int month);
