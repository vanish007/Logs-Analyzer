#pragma once

/**
 * Description:
 * Tales a null-terminated string and return its integer equivalent
 * if a string contains symbols besdies numbers than returns -1
 * 
 * Parametrs:
 * str - pointer to a null-terminated string
 * 
 * Return values:
 * Integer reprsentation of a string
 * 
 * Example:
 * StringToInt("999") returns 999;
 * StringToInt("Hello5") - returns -1;
 * 
 * Note:
 * empty string will return 0
 */
int StringToInt(const char* str);
