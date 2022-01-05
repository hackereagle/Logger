using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace scLin.Common
{
    public class LoggerDotNet
    {
        private static LoggerDotNet mInstance;
        private LoggerDotNet()
        { 
        }

        public static LoggerDotNet Instance 
        {
            get
            { 
                if(mInstance == null)
                {
                    mInstance = new LoggerDotNet();
                }
                return mInstance;
            }
        }
        
    }
}
