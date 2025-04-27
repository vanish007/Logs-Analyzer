#include <month_to_days.h>

int MonthToDays(int month) {
    if (month <= 0 || month > 12) return -1;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return std::accumulate(days, days + month, 0);
}
