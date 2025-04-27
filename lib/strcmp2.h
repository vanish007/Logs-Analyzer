#pragma once
/**
 * Description:
 * Compares two characters for equality
 *
 * Paramters:
 * first - the first character
 * second - the second character
 * 
 * Return values:
 * true if both characters are equal, false otherwise.
 *
 * Example:
 * bool result1 = StrCmp2('a', 'a'); // result1 = true
 * bool result2 = StrCmp2('a', 'b'); // result2 = false
 */
bool StrCmp2(const char first, const char second);

/** 
 * Description:
 * Compares two null-terminated byte strings lexicographically
 * 
 * Parametrs:
 * lptr, rptr - pointers to the null-terminated byte strings to compare
 * 
 * Return values:
 * -1 if lptr appears before rptr in lexicographical order
 *  0 if lptr and rptr compare equal
 *  1 if lptr appears after lptr in lexicographical order
 * 
 * Example:
 * int result1 = StrCmp2("AA", "AAA"); //reuslt1 = -1;
 * int result2 = StrCmp2("BB", "BB"); //reuslt2 = 0;
 * int result3 = StrCmp2("CCC", "CC"); //reuslt1 = 1; 
 */
int StrCmp2(const char* lptr, const char* rptr);


/**
 * Description:
 * Compares two null-terminated strings up to a specified cutoff
 *
 * Parametrs:
 * str1 - pointer to the first null-terminated string
 * str2 - pointer to the second null-terminated string
 * cut - the maximum number of characters to compare from each string
 * 
 * Return values: 
 * -1 if the first string is less than the second within the cutoff,
 *  1 if the first string is greater than the second within the cutoff,
 *  0 if the two strings are equal within the cutoff length.
 *
 * Example:
 * int result1 = StrCmp2("abcdef", "abcxyz", 3); // result1 = 0 (equal up to 3 characters)
 * int result2 = StrCmp2("abc", "abcxyz", 3);    // result2 = 0 (equal up to 3 characters)
 * int result3 = StrCmp2("abcdef", "abcxyz", 5);  // result3 = -1 (less)
 * int result4 = StrCmp2("xyz", "abc", 3);        // result4 = 1 (greater)
 */
bool StrCmp2(const char* str1, const char* str2, int cut); 