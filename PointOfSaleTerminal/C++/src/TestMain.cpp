#include <iomanip>
#include <fstream>
#include <iostream>

#include "PointOfSaleTerminal.h"

int main( int argc, char** argv )
{
    if( 2 != argc )
    {
        std::cout << "No commands file specified - Nothing to do exiting" << std::endl;
        std::cout << "Usage: PointOfSaleTerminal <input filename>" << std::endl;
    }
    else
    {
        PointOfSaleTerminal terminal;
        std::string priceFilename;

        // an argument was provided for a command file - open it
        // The expected format for this file is expected to be the pricing filename on the first line
        // and each successive line an item to scan
        std::ifstream cmdFile( argv[1] );

        // The file is opened properly and there is some content in it
        if( cmdFile.is_open() && !cmdFile.eof() )
        {
            getline( cmdFile, priceFilename );
            terminal.setPricing( priceFilename );
            
            while( !cmdFile.eof() )
            {
                std::string tmpStr;
                getline( cmdFile, tmpStr );
                if( !tmpStr.empty() )
                {
                    if( !terminal.scan( tmpStr ))
                    {
                        std::cout << "Scan of item " << tmpStr << " failed" << std::endl;
                    }
                }
            }
        }
        double total = terminal.calculateTotal();
        std::cout << setiosflags( std::ios::fixed ) << std::setprecision( 2 ) << "Total sale: $" << total << std::endl;
    }
    return 0;
}
