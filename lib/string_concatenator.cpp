#include <string_concatenator.h>

const char* ConcatenateString(const char* s1, 
                                const char* s2) {
    int len1 = StrLen2(s1);
    int len2 = StrLen2(s2);
    
    char* new_str = new char [len1 + len2 + 1];

    for (int i = 0; i < len1; ++i) {
        new_str[i] = s1[i];
    }
    for (int i = len1; i < len1+len2; ++i) {
        new_str[i] = s2[i-len1];
    }
    new_str[len1 + len2] = '\0';

    return &(new_str[0]);
}
