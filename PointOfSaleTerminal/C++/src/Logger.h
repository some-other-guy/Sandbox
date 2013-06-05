/*
 * This class is a place holder class for some logging functions that can be added.
 * Right now it simply dumps any log data to std::cout
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>

class Logger
{
public:
    Logger( std::string loggerName );
    virtual ~Logger();
    
    // Simple method that displays the message to the console along with the callers identifying string.
    void Log( std::string message );

private:
    std::string _name;
};

#endif /* LOGGER_H_ */
