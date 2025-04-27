#include <strcmp2.h>

bool StrCmp2(const char first,const char second) {
    return (first == second);
}

int StrCmp2(const char* lptr, const char* rptr) {
    int i = 0;
    if (rptr == nullptr && lptr == nullptr) {
        return 0;
    } else if (rptr == nullptr) {
        return -1;
    } else if (lptr == nullptr) {
        return 1;
    }
    while (*(lptr+i) != '\0' && *(rptr+i) != '\0') {
        if (*(lptr+i) < *(rptr+i)) {
            return -1;
        } else if (*(lptr+i) > *(rptr+i)) {
            return 1;
        }
        i++;
    }
    if (*(lptr+i) != '\0') {
        return 1;
    }
    if (*(rptr+i) != '\0') {
        return -1;
    }
    return 0;
}

bool StrCmp2(const char* str1, const char* str2, int cut) {
    for (int i = 0; i < cut; ++i) {
        if (str1[i] == '\0' && str2[i] == '\0') {
            return true;
        } else if (str1[i] == '\0' || str2[i] == '\0') {
            return false;
        } else if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}