#pragma once

#include <iostream>

#include <my_structs.h>

#include <string_to_int.h>

/**
 * File:
 * This header file contains functions that are used to parse log file lines
 * 
 * It contains declarations of FillRemoteAddr, ClearRemoteAddr, FillLocalTime,
 * FillRequest, ClearReqest, FillStatus, ClearStatus, FillBytesSend, 
 * ClearBytesSend and ClearMemory functions
 * 
 * Functions that start with 'Fill' are used to parce log file
 * They usually get 4 parametrs: i, j, buffer, kBufferSize
 * i and j are two indexes that are used to indicated the ends of an argument
 * buffer is a char array containing line of log file
 * kBufferSize is a size of a buffer
 * Functions that start with 'Clear' are used to clear memory that was provided
 * during the work of Fill functions with "= new char[]";
 * 
 * Example:
 * Functions FillLocalTime uses indexes i and j to find '[' and ']'
 * after it creates a new char array and creates a pointer to it.
 * everything between '[' and ']' will be written to this array
 * Function ClearLocalTime will delete allocated memory with delete [] local_time
 * 
 * Note:
 * Function ClearMemory uses other clear functions and as an argument gets 
 * log_val which is a LogFileValues structure containing value of others arguments that were
 * already proccessed in this line
 */

char* FillRemoteAddr(int& i, int& j, char buffer[], const int kBufferSize);

void ClearRemoteAddr(const char*& remote_addr);

char* FillLocalTime(int& i, int& j, char buffer[], const int kBufferSize);

void ClearLocalTime(const char*& local_time);

char* FillRequest(int& i, int& j, char buffer[], const int kBufferSize);

void ClearRequest(const char*& request);

char* FillStatus(int& i, int& j, char buffer[], const int kBufferSize);

void ClearStatus(const char*& status);

char* FillBytesSend(int& i, int& j, char buffer[], const int kBufferSize);

void ClearBytesSend(const char*& bytes_send);

void ClearMemory(LogFileValues log_val);