using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PointOfSaleTerminal
{
    class Logger
    {
        private string _name;

        public Logger(string nameIn)
        {
            _name = nameIn;
        }

        public void Log( string message )
        {
#if DEBUG
            System.Console.WriteLine( "Log: " + _name + " : " + message );
#endif
        }
    }
}
