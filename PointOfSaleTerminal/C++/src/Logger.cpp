#include <iostream>

#include "Logger.h"

Logger::Logger( std::string loggerName ) : _name( loggerName )
{

}

Logger::~Logger()
{
}

void Logger::Log( std::string message )
{
#ifdef LOGGING_ENABLED
    std::cout << "Log : " << _name << " : " << message << std::endl;
#endif
}
