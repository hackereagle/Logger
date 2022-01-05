#pragma once

#include "LoggerCommon.hpp"
#include "Logger.hpp"

#define LOG_TYPE_Start        0      
#define LOG_TYPE_Camera       1     
#define LOG_TYPE_Socket       2
#define LOG_TYPE_TeachData    3  
#define LOG_TYPE_Application  4
#define LOG_TYPE_Algorithm    5  
#define LOG_TYPE_Exception    6  
#define LOG_TYPE_Final        7      

#define LOG_LEVEL_LOGALL    0
#define LOG_LEVEL_LOGTRACE  1
#define LOG_LEVEL_LOGDEBUG  2
#define LOG_LEVEL_LOGINFO   3
#define LOG_LEVEL_LOGWARN   4
#define LOG_LEVEL_LOGERROR  5
#define LOG_LEVEL_LOGFATAL  6
#define LOG_LEVEL_LOGOFF    7

extern "C" {
#if _WIN32
DLLEXPORT_LOGGER_API int InitializeLogger(int fileLogLevel = LOG_LEVEL_LOGINFO, int uiLogLevel = LOG_LEVEL_LOGINFO);
DLLEXPORT_LOGGER_API void AsyncWrite(LogType type, const char *msg, int level = LOG_LEVEL_LOGINFO);
DLLEXPORT_LOGGER_API void RestarAsyncWrite();
DLLEXPORT_LOGGER_API void StopAsyncWrite();
#else
int InitializeLogger(int fileLogLevel = LOG_LEVEL_LOGINFO, int uiLogLevel = LOG_LEVEL_LOGINFO);
void AsyncWrite(int type, const char *msg, int level = LOG_LEVEL_LOGINFO);
void RestarAsyncWrite();
void StopAsyncWrite();
#endif // _WIN32
}