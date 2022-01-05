#pragma once
#ifndef _LOGGER_COMMON_H_
#define _LOGGER_COMMON_H_

#if _WIN32
    #ifdef EXPORTED_DLL
    #define DLLEXPORT_LOGGER_API __declspec(dllexport)
    #else
    #define DLLEXPORT_LOGGER_API __declspec(dllimport)
    #endif
#endif //_WIN32

#define LOGTYPE_VALUE_TABLE \
    LOGTYPE_TABLE(Start,      -1, "Start") \
    LOGTYPE_TABLE(Camera,      0, "Camera") \
    LOGTYPE_TABLE(Socket,      1, "Socket") \
    LOGTYPE_TABLE(TeachData,   2, "TeachData") \
    LOGTYPE_TABLE(Application, 3, "Application") \
    LOGTYPE_TABLE(Algorithm,   4, "Algorithm") \
    LOGTYPE_TABLE(Exception,   5, "Exception") \
    LOGTYPE_TABLE(Final,       6, "Final") 

#define LOGTYPE_TABLE(a, b, c) a = b,
enum class LogType {LOGTYPE_VALUE_TABLE};
#undef LOGTYPE_TABLE

inline const char* EnumToString(LogType value) {
#define LOGTYPE_TABLE(a, b, c) c,
    static const char* table[] = {LOGTYPE_VALUE_TABLE};
#undef LOGTYPE_TABLE
    return table[(int)(value) + 1];
};

#define LOGLEVEL_VALUE_TABLE \
    LOGLEVEL_TABLE(LOGALL,   0, "LOGALL") \
    LOGLEVEL_TABLE(LOGTRACE, 1, "LOGTRACE") \
    LOGLEVEL_TABLE(LOGDEBUG, 2, "LOGDEBUG") \
    LOGLEVEL_TABLE(LOGINFO,  3, "LOGINFO") \
    LOGLEVEL_TABLE(LOGWARN,  4, "LOGWARN") \
    LOGLEVEL_TABLE(LOGERROR, 5, "LOGERROR") \
    LOGLEVEL_TABLE(LOGFATAL, 6, "LOGFATAL") \
    LOGLEVEL_TABLE(LOGOFF,   7, "LOGOFF")

#define LOGLEVEL_TABLE(a,b,c) a = b, 
enum class LogLevel {LOGLEVEL_VALUE_TABLE};
#undef LOGLEVEL_TABLE

inline const char* EnumToString(LogLevel value) {
#define LOGLEVEL_TABLE(a,b,c) c,
    static const char* table[] = {LOGLEVEL_VALUE_TABLE};
#undef LOGLEVEL_TABLE
    return table[(int)value];
};

#define PRINT_STEP_TIME(STEP, ELAPSED_TIME_MS) std::cout << STEP << " spend " << ELAPSED_TIME_MS << " ms" << std::endl;
#endif // _LOGGER_COMMON_H_