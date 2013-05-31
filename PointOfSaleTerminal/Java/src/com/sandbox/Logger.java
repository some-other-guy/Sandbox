package com.sandbox;

public class Logger
{
    private String loggerName;
    
    public Logger( String loggerNameIn )
    {
        loggerName = loggerNameIn;
    }
    
    public void Log( String message )
    {
        System.out.println( "Log: " + loggerName + " :" + message );
    }
}
