using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace scLin.Common
{
    public enum LogType
    { 
        Start = -1,
        Camera = 0,
        Socket,
        TeachData,
        Application,
        Algorithm,
        Exception,
        Final
    }

    public enum LogLevel
    { 
        LOGALL = 0,
        LOGTRACE,
        LOGDEBUG,
        LOGINFO,
        LOGWARN,
        LOGERROR,
        LOGFATAL,
        LOGOFF,
    }

    public class LoggerDotNet
    {
        private static LoggerDotNet mInstance;
        private LoggerDotNet()
        { 
        }

        private static object mLock = new object();
        public static LoggerDotNet Instance 
        {
            get
            { 
                if(mInstance == null)
                {
                    lock (mLock)
                    { 
                        mInstance = new LoggerDotNet();
                    }
                }
                return mInstance;
            }
        }

        [DllImport("Logger.dll", EntryPoint ="InitializeLogger")]
        private static extern int mInitializeLogger(int fileLogLevel, int uiLogLevel);
        public int InitializeLogger(LogLevel fileLogLevel = LogLevel.LOGINFO, LogLevel uiLogLevel = LogLevel.LOGINFO)
        {
            return mInitializeLogger((int)fileLogLevel, (int)uiLogLevel);
        }

        [DllImport("Logger.dll", EntryPoint = "AsyncWrite")]
        private static extern void mAsyncWrite(int logType, byte[] msg, int logLevel);
        public void AsyncWrite(LogType type, string msg, LogLevel level = LogLevel.LOGINFO)
        {
            byte[] msgChar = System.Text.Encoding.ASCII.GetBytes(msg);
            mAsyncWrite((int)type, msgChar, (int)level);
        }

        [DllImport("Logger.dll", EntryPoint = "RestartAsyncWrite")]
        private static extern void mRestartAsyncWrite();
        public void RestartAsyncWrite()
        {
            mRestartAsyncWrite();
        }

        [DllImport("Logger.dll", EntryPoint = "StopAsyncWrite")]
        private static extern void mStopAsyncWrite();
        public void StopAsyncWrite()
        {
            mStopAsyncWrite();
        }
    }
}
