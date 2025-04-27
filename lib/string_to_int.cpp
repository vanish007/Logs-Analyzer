#include <string_to_int.h>

int StringToInt(const char* str) {
    long long num = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        } else {
            int t = (int)(str[i]) - 48;
            num += t;
            num *= 10;
        }
        ++i;
    }
    num /= 10;
    return num;
}
