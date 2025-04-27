#pragma once

#include <strlen2.h>

/**
 * Description:
 * This function takes two C-style strings as input and returns a 
 * new dynamically allocated string that contains the concatenation 
 * of the two input strings.
 *
 * Patametrs:
 * s1 - pointer to the first C-style string (null-terminated).
 * s2 - pointer to the second C-style string (null-terminated).
 * 
 * Return values:
 * pointer to a newly allocated string containing the 
 * concatenation of s1 and s2. The caller is responsible 
 * for deallocating the memory using 'delete[]'.
 *
 * Note:
 * The function assumes that both s1 and s2 are valid non-null 
 * pointers. If either s1 or s2 is a null pointer, the behavior 
 * of the function is unspecified.
 */
const char* ConcatenateString(const char* s1, const char* s2);
