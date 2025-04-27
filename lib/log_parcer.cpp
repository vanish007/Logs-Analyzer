#include <log_parcer.h>


int Hesh(const char* s) {
    int n = 1;
    int i = 0;
    while ((s[i]) != '\0') {
        n = n*26 + s[i];
        i++;
    }
    if (n < 0) n*=-1;
    return n;
}

bool compareBySecond(const std::pair<const char*, int>& a, 
                    const std::pair<const char*, int>& b) {
    return a.second > b.second;
}

void LogParce(const ArgumentCheck arg_check, const ArgumentValues arg_values, 
                std::ifstream& fin, std::ofstream& fout) {  
    //creating window for analyzing request;
    const int kWindowSize = arg_check.window ? arg_values.window : 0; 
    int left = 0;
    int right = 0;
    int max_window_size = std::numeric_limits<int>::min();
    std::deque<int> time;

    //creating hash_map for analyzing error request
    const int kHashMapSize = 32768;
    std::pair<const char*, int> hash_map[kHashMapSize]{};

    //creates min and max arguments that are equal to 'from' and 'to' values
    int line_number = 0;
    const int kMinTimeInLog = arg_check.from ? arg_values.from : std::numeric_limits<int>::min();
    const int kMaxTimeInLog = arg_check.to ? arg_values.to : std::numeric_limits<int>::max();
    const int kBufferSize = 16192;
    while (!fin.eof()) {
        line_number++;

        //create a buffer
        LogFileValues log_val;
        bool flag = false;
        char buffer[kBufferSize]{};
        int i = 0;
        int j = i;

        //fill a buffer
        fin.getline(buffer, kBufferSize);
        int size = StrLen2(buffer);
        if (size <= 0 || size >= kBufferSize) continue;
        buffer[size] = '\0';

        //parcing log values
        log_val.remote_addr = FillRemoteAddr(i, j, buffer, size);
        if (log_val.remote_addr == nullptr) {
            ClearMemory(log_val);
            continue;
        }
        log_val.local_time = FillLocalTime(i, j, buffer, size);
        if (log_val.local_time == nullptr) {
            ClearMemory(log_val);
            continue;
        }

        //turning time from timestamps format to int
        const int kLocalTimeValue = LocalTimeParce(log_val.local_time, StrLen2(log_val.local_time));
        if (kLocalTimeValue == -1) {
            ClearMemory(log_val);
            continue;
        }
        //if we are outside of range 'from'-'to' than exit or continue
        if (kLocalTimeValue < kMinTimeInLog) continue;
        if (kLocalTimeValue > kMaxTimeInLog) break;
        time.push_front(kLocalTimeValue);

        log_val.request = FillRequest(i, j, buffer, size);
        if (log_val.request == nullptr) {
            ClearMemory(log_val);
            continue;
        }
        log_val.status = FillStatus(i, j, buffer, size);
        if (log_val.status == nullptr) {
            ClearMemory(log_val);
            continue;
        }
        //turning request status into int
        const int kStatusCode = StringToInt(log_val.status);
        if (kStatusCode == -1) {
            ClearMemory(log_val);
            continue;
        }
        log_val.bytes_send = FillBytesSend(i, j, buffer, size);
        if (log_val.bytes_send == nullptr) {
           ClearMemory(log_val);
            continue;
        }

        //if windows option is present start analyse
        if (arg_check.window) {
            time.push_front(kLocalTimeValue);
            while (time.front() - time.back() + 1 > kWindowSize) {
                time.pop_back();
            }
            int t_size = time.size();
            if (t_size > max_window_size) {
                max_window_size = t_size;
                left = time.back();
                right = time.front();
            }       
        }
        //analysing error requests
        if (500 <= kStatusCode && kStatusCode <= 599 && arg_check.output) {
            if (arg_check.stats) {
                int hash = Hesh(log_val.request) % kHashMapSize;
                int size2 = StrLen2(log_val.request);
                char* request_copy = new char[size2 + 1];
                for (int ii = 0; ii < size2 + 1; ++ii) {
                    request_copy[ii] = log_val.request[ii];
                }
                if (hash_map[hash].first == nullptr) {
                    hash_map[hash].first = request_copy;
                    hash_map[hash].second += 1;
                } else {
                    bool flag = false;
                    while (hash_map[hash].first != nullptr) {
                        if (StrCmp2(request_copy, hash_map[hash].first) == 0) {
                            hash_map[hash].second += 1;
                            flag = true;
                            break;
                        }
                        hash++;
                        hash = hash % kBufferSize;
                    }
                    if (!flag) {
                        hash_map[hash].first = request_copy;
                        hash_map[hash].second += 1;
                    }
                }
            }


            if (arg_check.print) {
                std::cout << log_val.request << ' ' << log_val.status 
                << std::endl;
            }
            fout << log_val.request << ' ' << log_val.status << std::endl;
        } 
        ClearMemory(log_val);
    }
    if (arg_check.window) {
        long long l = left;
        long long r = right;
        std::time_t timestamp1 = l;
        std::time_t timestamp2 = r;
        std::cout << "A period of time lasting " << kWindowSize 
        << " seconds during which the number of requests was maximum was from \""
         << std::ctime(&timestamp1) << '(' << left << ')' 
         << " to " << std::ctime(&timestamp2) 
         << '(' << right << ')' << "\" and had exactly " << max_window_size/2 
         << " requests" << std::endl;
    }
    if (arg_check.stats && arg_check.output) {
        std::sort(std::begin(hash_map), std::end(hash_map), compareBySecond);
        int cnt = 0;
        for (int i = 0; i < kHashMapSize; ++i) {
            if (hash_map[i].first != nullptr) {
                std::cout << hash_map[i].second << "     " << hash_map[i].first
                 << std::endl;
                ++cnt;
                if (cnt >= arg_values.stats) {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < kHashMapSize; ++i) {
        delete[] hash_map[i].first;
    }   
    
}