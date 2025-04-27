#include <local_time_parcer.h>

int LocalTimeParce(const char local_time[], const int kLocalTimeSize) {
    //we get string in format [DD:MMM:YYYY:HH:MM:SS -0000]
    char t_seconds[] = {local_time[18], local_time[19], '\0'}; //indexes [18] and [19] are amount of seconds in SS fromat
    int seconds = StringToInt(t_seconds);
    if (seconds == -1) {
        return -1;
    }

    char t_days[] = {local_time[0], local_time[1], '\0'}; //indexes [0] and [1] are amount of days in DD fromat. for example
    int days = StringToInt(t_days);
    days -= 1; //because if it is for example Jul 1st than 24 hours didnt pass yet
    if (days == -1) {
        return -1;
    }
    seconds += days * 86400;


    char t_month[] = {local_time[3], local_time[4], local_time[5], '\0'}; //indexes [3], [4] and [5] are name of the month. for example "JUL";
    int month = MonthToNum(t_month);
    if (month < 1 || month > 12) {
        return -1;
    }
    seconds += MonthToDays(month) * 86400;


    char t_year[] = {local_time[7], local_time[8], local_time[9], local_time[10], '\0'}; //those numbers are indexes of the year
    int year = StringToInt(t_year);
    if (year == -1) {
        return -1;
    }
    for (int i = 1970; i < year; i++) {
        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) {
            seconds += 86400;
        }
    }
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) && month > 2) {
        seconds += 86400;
    }
    year -= 1970;
    if (year < 0) {
        return -1;
    }
    seconds += year * 365 * 86400;


    char t_hours[] = {local_time[12], local_time[13], '\0'}; //those numbers are indexes of hours
    int hours = StringToInt(t_hours);
    if (hours == -1) {
        return -1;
    }
    seconds += hours * 3600;


    char t_minutes[] = {local_time[15], local_time[16], '\0'}; //those numbers are indexes of minutes
    int minutes = StringToInt(t_minutes);
    if (minutes == -1) {
        return -1;
    }
    seconds += minutes * 60;


    char t_UTC[] = {local_time[22], local_time[23], local_time[24], local_time[25], '\0'}; //those numbers are UTC time zone
    if (local_time[21] == '+') { //those index is plus or minus UTC for example -0400
        seconds -= ((local_time[22]-'0')*10 + (local_time[23]-'0')) * 3600;
        seconds -= ((local_time[24]-'0')*10 + (local_time[25]-'0')) * 60;
    } else if (local_time[21] == '-') {
        seconds += ((local_time[22]-'0')*10 + (local_time[23]-'0')) * 3600;
        seconds += ((local_time[24]-'0')*10 + (local_time[25]-'0')) * 60;
    } else {
        return -1;
    }
    if (seconds < 0) {
        return -1;
    }
    return seconds;
}