#include <iostream>

#include "utilities.h"

int main( int argc, char** argv )
{
    int32_t num1 = 22;
    int32_t num2 = 2;
    std::string str( "siluoraM miJ" );

    Sandbox::Utilities::Reverse( str );
    std::cout << str << std::endl;

    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    Sandbox::Utilities::Swap( num1, num2 );
    std::cout << "Now num1 = " << num1 << ", num2 = " << num2 << std::endl;

    std::cout << Sandbox::Utilities::GetMax( num1, num2 ) << " is larger then "
        << Sandbox::Utilities::GetMin( num1, num2 )<< std::endl;
    return 0;
}
