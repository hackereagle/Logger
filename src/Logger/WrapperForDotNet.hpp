#pragma once

#include "LoggerCommon.h"
#include "Logger.h"

#define LOGLEVEL_VALUE_TABLE(a, b, c) a b
#define LOGLEVEL_VALUE_TABLE
#undef LOGLEVEL_TABLE

#if _WIN32
extern "C" {
DLLEXPORT_LOGGER_API int InitializeLogger();
}
#else
int InitializeLogger(int a = LOGALL);
#endif // _WIN32