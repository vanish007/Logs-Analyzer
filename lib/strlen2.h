#pragma once


/**
 * Description:
 * Computes the length of a C-style string
 *
 * This function takes a pointer to a null-terminated string and returns
 * the number of characters in the string, not including the null terminator
 * 
 * The function does not modify the input string
 *
 * Parametrs: 
 * A pointer to a null-terminated string
 * This should be a valid pointer to a character array
 * 
 * Return values:
 * The length of the string as an integerr.
 * 
 * Example:
 * int length1 = StrLen2("Hello");     // length1 = 5
 * int length2 = StrLen2("");          // length2 = 0
 * int length3 = StrLen2("World!");    // length3 = 6
 * 
 * Note:
 * Passing nullptr would lead to undefined behavior.
 */
int StrLen2(const char* str);