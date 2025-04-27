#include <log_processor.h>

char* FillRemoteAddr(int& i, int& j, char buffer[], const int KBufferSize) {
    bool flag = false;
    while (buffer[j] != ' ') {
        if (buffer[j] == '\0' || j > KBufferSize) return nullptr;
        ++j;
    }
    const int kRemoteAddrSize = j-i+1;
    char* remote_addr = new char[kRemoteAddrSize];
    while (i != j) {
        if (i > j) return nullptr;

        remote_addr[i] = buffer[i];
        ++i;
    }
    remote_addr[i] = '\0';
    return remote_addr;
}

void ClearRemoteAddr(const char*& remote_addr) {
    delete[] remote_addr;
    remote_addr = nullptr;
}

char* FillLocalTime(int& i, int& j, char buffer[], const int KBufferSize) {
    while (buffer[i] != '[') {
        if (i >= KBufferSize) return nullptr;
        ++i;
    }

    ++i;
    j = i;
    while(buffer[j] != ']') {
        if (j >= KBufferSize) return nullptr;
        
        ++j;
    }
    if (buffer[j+1] != ' ' || buffer[j+2] != '\"') return nullptr;
    
    const int kLocalTimeSize = j-i+1;
    char* local_time = new char[kLocalTimeSize];
    int k = 0;
    while (i != j) {
        if (i > j) return nullptr;
        local_time[k] = buffer[i];
        ++i;
        ++k;
    }
    local_time[k] = '\0';
    return local_time;
}

void ClearLocalTime(const char*& local_time) {
    delete[] local_time;
    local_time = nullptr;
}

char* FillRequest(int& i, int& j, char buffer[], const int KBufferSize) {
    while (buffer[i] != '\"') {
        if (i >= KBufferSize) return nullptr;
        ++i;
    }
    ++i;
    j = KBufferSize - 1;
    j = i+1;
    while(buffer[j] != '\"') {
        if (j >= KBufferSize) return nullptr;
        ++j;
    }
    if (buffer[j+1] != ' ' || '9' < buffer[j+2] || '0' > buffer[j+2]) return nullptr;
    const int kRequestSize = j-i+1;
    char* request = new char [kRequestSize];
    int k = 0;
    while (i != j) {
        if (i > j) return nullptr;
        request[k] = buffer[i];
        ++i;
        ++k;
    }
    request[k] = '\0';
    return request;
}

void ClearRequest(const char*& request) {
    delete[] request;
    request = nullptr;
}

char* FillStatus(int& i, int& j, char buffer[], const int KBufferSize) {
    while (buffer[i] != ' ') {
        if (i >= KBufferSize) return nullptr;
        ++i;
    }
    ++i;
    j = i+1;
    while(buffer[j] != ' ') {
        if (j >= KBufferSize) return nullptr;
        ++j;
    }
    if ('9' < buffer[j+1] || '0' > buffer[j+1]) return nullptr;
    const int kStatusSize = j-i+1;
    char* status = new char [kStatusSize];
    int k = 0;
    while (i != j) {
        if (i > j) return nullptr;
        status[k] = buffer[i];
        ++i;
        ++k;
    }
    status[k] = '\0';
    return status;
}

void ClearStatus(const char*& status) {
    delete[] status;
    status = nullptr;
}

char* FillBytesSend(int& i, int& j, char buffer[], const int KBufferSize) {
    bool flag = false;
    const int kBytesSendSize = KBufferSize-i;
    char* bytes_send = new char [kBytesSendSize];
    ++i;
    int k = 0;
    while (i != KBufferSize) {
        if (i > KBufferSize) flag = true;
        bytes_send[k] = buffer[i];
        ++i;
        ++k;
    }
    if (flag) {
        return nullptr;
    }
    bytes_send[k] = '\0';
    return bytes_send;
}

void ClearBytesSend(const char*& bytes_send) {
    delete[] bytes_send;
    bytes_send = nullptr;
}

void ClearMemory(LogFileValues log_val) {
    if (log_val.remote_addr != nullptr) ClearRemoteAddr(log_val.remote_addr);

    if (log_val.local_time != nullptr) ClearLocalTime(log_val.local_time);

    if (log_val.request != nullptr) ClearRequest(log_val.request);

    if (log_val.status != nullptr) ClearStatus(log_val.status);

    if (log_val.bytes_send != nullptr) ClearRemoteAddr(log_val.bytes_send);
}