#include <month_to_num.h>

int MonthToNum(const char* month) {
    if (StrCmp2(month, "Jan") == 0) return 1;
    if (StrCmp2(month, "Feb") == 0) return 2;
    if (StrCmp2(month, "Mar") == 0) return 3;
    if (StrCmp2(month, "Apr") == 0) return 4;
    if (StrCmp2(month, "May") == 0) return 5;
    if (StrCmp2(month, "Jun") == 0) return 6;
    if (StrCmp2(month, "Jul") == 0) return 7;
    if (StrCmp2(month, "Aug") == 0) return 8;
    if (StrCmp2(month, "Sep") == 0) return 9;
    if (StrCmp2(month, "Oct") == 0) return 10;
    if (StrCmp2(month, "Nov") == 0) return 11;
    if (StrCmp2(month, "Dec") == 0) return 12;
    return -1;
}
