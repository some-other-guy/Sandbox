package com.sandbox;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class TestMain
{
    public static void main( String[] args )
    {
        if( 1 != args.length )
        {
            System.out.println( "No commands file specified - Nothing to do exiting" );
            System.out.println( "Usage: PointOfSaleTerminal <input filename>" );
        }
        else
        {
            PointOfSaleTerminal terminal = new PointOfSaleTerminal();
            BufferedReader buffer;
            try
            {
                buffer = new BufferedReader( new FileReader( args[0] ));
                String line = buffer.readLine();
                if( null != line )
                {
                    terminal.setPricing( line );
                    while(( line = buffer.readLine() ) != null )
                    {
                        terminal.scan( line );
                    }
                }
            } 
            catch( FileNotFoundException e )
            {
                System.out.println( e.getMessage() );
            } 
            catch( IOException e )
            {
                System.out.println( e.getMessage() );
            }
            System.out.println( "Total sale: $" + terminal.calculateTotal().toString() );
        }
    }
}
