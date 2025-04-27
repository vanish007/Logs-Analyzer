#pragma once

#include <strcmp2.h>

/**
 * Description:
 * Validates command-line arguments based on given reference character.
 * This function checks whether the provided argument `arg) matches any of the valid
 * command-line options associated with the specified reference character (ref).
 * 
 * The valid command-line options for each reference character are as follows:
 * - o: `{"-o", "--output", "--output="}`
 * - p: `{"-p", "--print"}`
 * - s: `{"-s", "--stats", "--stats="}`
 * - w: `{"-w", "--window", "--window="}`
 * - f: `{"-f", "--from", "--from="}`
 * - t: `{"-t", "--to", "--to="}`
 * 
 * The function returns:
 * - 0 if the argument does not match any of the valid options.
 * - 1 if the argument matches a short or long option 
 *      (that does not expect an additional value).
 * - 2 if the argument matches a long option that expects an additional value 
 *     (indicated by a trailing "=").
 *
 * Parametrs:
 * arg - the argument string to validate.
 * ref - a reference character that determines which set of
 *       options to check against.
 * 
 * Return values:
 * Returns the validation result based on matching criteria.
 */

int Validate(char* arg, char ref);