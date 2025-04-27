#pragma once

#include <limits>

// structure for checking argument flags
struct ArgumentCheck {
    bool log = false;        // flag indicating 'log' file presence
    bool output = false;     // flag indicating 'outpu't argument presence
    bool print = false;      // flag indicating 'print' argument presence
    bool stats = false;      // flag indicating 'stats' argument presence
    bool window = false;     // flag indicating 'window' argument presence
    bool from = false;       // flag indicating 'from' argument presence
    bool to = false;         // flag indicating 'to argument presence
    bool help = false;         // flag indicating 'help argument presence

    bool global = false;     // flag indicating a global argument
    bool error = false;      // flag indicating if an error occurred
};

// structure for storing values of command line arguments
struct ArgumentValues {
    char* log = nullptr;     // pointer to log file path
    char* output = nullptr;  // pointer to output file path
    int stats = 10;          // default 'stats' value
    int window = 0;          // default 'window' value
    int from = 0;            // default 'from' value
    int to = std::numeric_limits<int>::max(); // default 'to' value
};

// structure for holding log file related values
struct LogFileValues {
    const char* remote_addr = nullptr;  // remote address in log
    const char* local_time = nullptr;    // local time of the log entry
    const char* request = nullptr;        // request details from the log
    const char* status = nullptr;         // status of the request
    const char* bytes_send = nullptr;     // bytes sent in the request
};
