#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>

#define INFO_LOG( logger, message ) StaticLog( logger, message )

namespace Sandbox
{
    class Logger
    {
    public:
        Logger();
        virtual ~Logger();

        static void StaticLog( std::string message );
    };
}
#endif
