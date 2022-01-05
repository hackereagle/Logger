#include "WrapperForDotNet.hpp"

int InitializeLogger(int fileLogLevel, int uiLogLevel)
{
	return (int)Logger::GetInstance().Initialize(static_cast<LogLevel>(fileLogLevel), static_cast<LogLevel>(uiLogLevel));
}

void AsyncWrite(int type, const char *msg, int level)
{
	Logger::GetInstance().AsyncWrite(static_cast<LogType>(type), msg, static_cast<LogLevel>(level));
}

void RestarAsyncWrite()
{
	Logger::GetInstance().RestarAsyncWrite();
}

void StopAsyncWrite()
{
	Logger::GetInstance().StopAsyncWrite();
}