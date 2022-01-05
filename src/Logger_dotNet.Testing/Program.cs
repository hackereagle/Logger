using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using scLin;
using scLin.Common;

namespace scLin
{
    class Program
    {
        static void Main(string[] args)
        {
            LoggerDotNet.Instance.InitializeLogger();
            LoggerDotNet.Instance.AsyncWrite(LogType.Application, "test");
            Console.ReadLine();
        }
    }
}
